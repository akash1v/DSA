import numpy as np
    
def LongestAlternatingSubsequence(A):
    n = len(A)
    increasing = np.ones(n)
    decreasing = np.ones(n)

    for i in range(1, n):
        for j in range(i):
            if A[i] > A[j]:
                increasing[i] = max(increasing[i], decreasing[j] + 1)
            elif A[i] < A[j]:
                decreasing[i] = max(decreasing[i], increasing[j] + 1)

    return max(max(increasing), max(decreasing))

if __name__ == "__main__":
    A = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 7]
    print("Length : ", LongestAlternatingSubsequence(A))