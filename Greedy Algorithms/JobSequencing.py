class Job:
    def __init__(self, name, profit, deadline):
        self.name = name
        self.profit = profit
        self.deadline = deadline
    
def JobSequencing(jobs):
    max_time = max([job.deadline for job in jobs])
    sorted_jobs = sorted(jobs, key= lambda x:x.profit, reverse=True)
    max_profit = 0
    available_slots = [None for i in range(max_time)]
    for job in sorted_jobs:
        for i in range(job.deadline, 0, -1):
            if available_slots[i-1] == None:
                available_slots[i-1] = job.name
                max_profit += job.profit
                break

    return max_profit, available_slots

jobs = [
    Job("one", 15, 2),
    Job("two", 10, 1),
    Job("three", 20, 2),
    Job("four", 1, 3),
    Job("five", 5, 3),
]

print(JobSequencing(jobs))