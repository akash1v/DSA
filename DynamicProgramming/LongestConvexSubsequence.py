import numpy as np
def LongestConvexSubsequence(A):
    n = len(A)
    if n < 3:
        return n

    dm, increasing, decreasing = np.ones(n), np.ones(n), np.ones(n)

    for i in range(1, n):
        for j in range(i):

            if A[i] > A[j]:
                increasing[i] = max(increasing[i], increasing[j] + 1)
                dm[i] = max(dm[i], increasing[i])

            if A[i] < A[j]:
                decreasing[i] = max(decreasing[i], decreasing[j] + 1)
                dm[i] = max(dm[i], decreasing[i])

            if (i - j >= 2) and (A[i] - A[j]) > (A[j] - A[j - 1]):
                dm[i] = max(dm[i], 2 + dm[j - 1])
    n
    return max(dm)

if __name__ == "__main__":
    A = [1, 3, 2, 5, 4, 7, 6, 8, 9]
    print("Length : ", LongestConvexSubsequence(A))
