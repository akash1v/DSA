class File:
    def __init__(self, name, size):
        self.name = name
        self.size = size

def OptimalMege(files):
    sorted_files = sorted(files, key=lambda x:x.size)
    min_val = 0
    sequence = []
    while len(sorted_files)>1:
        f1 = sorted_files.pop(0)
        f2 = sorted_files.pop(0)
        min_val += f1.size + f2.size
        sequence.append(f"{f1.name} <- {f2.name}")
        f1.size += f2.size
        sorted_files.append(f1)
        sorted_files = sorted(sorted_files, key=lambda x:x.size)
    return min_val, sequence

files = [
    File("1", 20),
    File("2", 30),
    File("3", 10),
    File("4", 5),
    File("5", 30),
]

print(OptimalMege(files))