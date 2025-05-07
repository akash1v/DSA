import numpy as np
class Task:
    def __init__(self, id, time_in_machines):
        self.id = id
        self.time_from = np.zeros(len(time_in_machines), dtype=int)
        self.time_to = np.array(time_in_machines)

    def add_time(self, time, machine = -1):
        if machine == -1:
            self.time_from += time
            self.time_to += time
        else:
            self.time_from[machine] += time
            self.time_to[machine] += time

    def execution_time(self, machine):
        return self.time_to[machine] - self.time_from[machine]

    def min_time_machine(self):
        return np.argmin(self.time_to)
    
class Machine:
    def __init__(self, id):
        self.id = id
        self.queue = []

    def execute(self, task):
        self.queue.append(task)

class MaxMin:
    def __init__(self, no_of_machines):
        self.machines = [Machine(i) for i in range(no_of_machines)]

    def execution(self, tasks):
        while tasks:
            t_id, m_id = self.largest_task_machine(tasks)
            task = tasks.pop(t_id)
            self.machines[m_id].execute(task)

            execution_time = task.execution_time(m_id)
            for task in tasks:
                task.add_time(execution_time, m_id)
        self.print()

    def largest_task_machine(self, tasks):
        machines = [task.min_time_machine() for task in tasks]
        times = [tasks[i].execution_time(machines[i]) for i in range(len(tasks))]
        largest = np.argmax(times)
        return largest, machines[largest]

    def print(self):
        print()
        for machine in self.machines:
            print(f"Machine {machine.id} : ")
            for task in machine.queue:
                print(
                    f" Task {task.id} executing in machine "
                    f"{machine.id} from {task.time_from[machine.id]}"
                    f" to {task.time_to[machine.id]}"
                )
        print()


task_zero = Task(0, [5, 7])
task_one = Task(1, [2, 4])
task_two = Task(2, [3, 1])
tasks = [task_zero, task_one, task_two]

balancer = MaxMin(2)
balancer.execution(tasks)