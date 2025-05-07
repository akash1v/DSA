class Task:
    def __init__(self, id, time_to):
        self.id = id
        self.time_from = 0
        self.time_to = time_to
    
    def execution_time(self):
        return self.time_to - self.time_from
    
class Machine:
    def __init__(self, id):
        self.id = id
        self.queue = []

    def execute(self, task):
        if self.queue:
            task.time_from += self.queue[-1].time_to
            task.time_to += self.queue[-1].time_to

        self.queue.append(task)
    
    def free_time(self):
        if self.queue:
            return self.queue[-1].time_to
        return 0

class RoundRobin:
    def __init__(self, no_of_machines):
        self.machines = [Machine(i) for i in range(no_of_machines)]
        self.timer = 0
        self.m_id = 0
        self.max_id = no_of_machines

    def execution(self, tasks):
        while tasks:
            task = tasks.pop(0)
            time = self.timer - self.machines[self.m_id].free_time()
            if time > 0:
                task.time_from += time
                task.time_to += time
            self.machines[self.m_id].execute(task)
            self.m_id += 1
            if(self.m_id >= self.max_id):
                self.m_id -= self.max_id
        self.print()
        self.update_timer()

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
                    f"Task {task.id} executing in machine "
                    f"{machine.id} from {task.time_from} "
                    f"to {task.time_to}"
                )
        print()

task_zero = [Task("0", 8)]
task_one = [Task("1_a", 5), Task("1_b", 6)]
task_two = [Task("2_a", 7), Task("2_b", 3), Task("2_c", 4)]

balancer = RoundRobin(3)
balancer.execution(task_zero)
balancer.execution(task_one)
balancer.execution(task_two)