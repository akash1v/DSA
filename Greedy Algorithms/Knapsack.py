class Object:
    def __init__(self, name, value, weight):
        self.name = name
        self.value = value
        self.weight = weight
        self.vperw = value/weight


def Knapsack(objects, capacity):
    n = len(objects)
    sorted_objects = sorted(objects, key=lambda x:x.vperw, reverse=True)
    max_value = 0
    selected_objects = []
    selected_weights = []
    for object in sorted_objects:
        selected_objects.append(object.name)
        if object.weight <= capacity:
            selected_weights.append(object.weight)
            max_value += object.value
            capacity -= object.weight
        else:
            selected_weights.append(capacity)
            max_value += object.vperw*capacity
            capacity = 0
            break
    return max_value, selected_objects, selected_weights

objects = [
    Object("Mango", 1, 10),
    Object("Gold", 100, 5),
    Object("silver", 5, 3)
]

print(Knapsack(objects, 7))