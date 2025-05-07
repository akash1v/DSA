import numpy as np
class Task:
    def __init__(self, id, time_in_machines):
        self.id = id
        self.time_from = np.zeros(len(time_in_machines), dtype=int)
        self.time_to = np.array(time_in_machines)
        self.executed = False

    def add_time(self, time, machine = -1):
        if machine == -1:
            self.time_from += time
            self.time_to += time
        else:
            self.time_from[machine] += time
            self.time_to[machine] += time

    def execution_time(self, machine = None):
        if self.executed:
            return self.time_to - self.time_from
        return self.time_to[machine] - self.time_from[machine]

    def min_time_machine(self):
        return np.argmin(self.time_to)
    
class Machine:
    def __init__(self, id):
        self.id = id
        self.queue = []

    def execute(self, task):
        time_from = task.time_from[self.id]
        time_to = task.time_to[self.id]
        task.time_from = time_from
        task.time_to = time_to

        self.queue.append(task)
        task.executed = True

    def free_time(self):
        if self.queue:
            return self.queue[-1].time_to - self.queue[0].time_from
        return 0
    
class MaxMin:
    def __init__(self, no_of_machines):
        self.machines = [Machine(i) for i in range(no_of_machines)]
        self.timer = 0

    def execution(self, tasks):
        self.update_time_in(tasks)
        while tasks:
            t_id, m_id = self.largest_task_machine(tasks)
            task = tasks.pop(t_id)
            self.machines[m_id].execute(task)

            execution_time = task.execution_time()
            for task in tasks:
                task.add_time(execution_time, m_id)
        self.print()
        self.update_timer()

    def update_time_in(self, tasks):
        for machine in self.machines:
            wait_time = machine.free_time() + self.timer
            for task in tasks:
                task.add_time(wait_time, machine.id)
                
    def largest_task_machine(self, tasks):
        machines = [task.min_time_machine() for task in tasks]
        times = [
            tasks[i].execution_time(machines[i])
            for i in range(len(tasks))
        ]
        largest = np.argmax(times)
        return largest, machines[largest]

    def update_timer(self, time=1):
        self.timer += time
        for machine in self.machines:
            for task in machine.queue:
                execution_time = task.execution_time()
                if execution_time > time:
                    task.time_from += time
                    break
                if execution_time == time:
                    machine.queue.pop()
                    break        
                machine.queue.pop()
                time -= execution_time
    
    def print(self):
        print(f"Time : {self.timer}")
        for machine in self.machines:
            print(f"Macine {machine.id} : ")
            for task in machine.queue:
                print(
                    f" Task {task.id} executing in machine "
                    f"{machine.id} from {task.time_from}"
                    f" to {task.time_to}"
                )
        print()



task_zero = [Task("0", [5, 7])]
task_one = [Task("1_a", [2, 4]), Task("1_b", [3, 4])]
task_two = [Task("2_a", [5, 2]), Task("2_b", [6, 5]), Task("2_c", [1, 2])]

balancer = MaxMin(2)
balancer.execution(task_zero)
balancer.execution(task_one)
balancer.execution(task_two)