import numpy as np
def Knapsack01(values, weights,capacity):
    n = len(values)
    dm = np.zeros((n + 1, capacity + 1))
    for i in range(0, n):
        for j in range(1, capacity + 1):
            if weights[i] <= j:
                cost = values[i] + dm[i][j - weights[i]]
                dm[i+1][j] = max(dm[i][j], cost)
            else:
                dm[i+1][j] = dm[i][j]
    
    selected_items = []
    i, j = n, capacity 
    while i > 0 and j > 0:
        if dm[i][j] != dm[i - 1][j]:
            selected_items.append(i - 1)
            j-=weights[i-1]
        i-=1
    return selected_items

if __name__ == "__main__":
    keys = ["A", "B", "C", "D", "E", "F"]
    values = [1,2,5,6,9,4]
    weights = [2,3,4,5,10,3]
    selected_items = Knapsack01(values, weights, 15)

    selected_keys = []
    for i in selected_items:
        selected_keys.append(keys[i])
    print(selected_keys)
 