import numpy as np
def LongestIncreasingSubsequence(array):
    n = len(array)
    dm = np.ones(n)

    for i in range(1, n):
        for j in range(i):
            if array[i] > array[j]:
                dm[i] = max(dm[i], dm[j] + 1)
    
    return max(dm)

if __name__ == "__main__":
    array = [3,1,4,1,5,9,2,6]
    print("Length : ", LongestIncreasingSubsequence(array))