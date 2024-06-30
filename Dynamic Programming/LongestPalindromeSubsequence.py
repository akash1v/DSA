import numpy as np

def LongestPalindromeSubsequence(A):
    n = len(A)
    dm = np.zeros((n,n))

    for i in range(n):
        dm[i][i] = 1

    for length in range(2, n + 1):
        for i in range(n - (length - 1)):
            j = i + (length - 1)

            if A[i] == A[j]:
                dm[i][j] = dm[i + 1][j - 1] + 2 
            else:
                dm[i][j] = max(dm[i + 1][j], dm[i][j - 1])

    return dm[0][n - 1]

if __name__ == "__main__":
    A = [1, 2, 6, 2, 4, 6, 8, 2, 4, 1, 6, 9, 3]
    print("Length : ", LongestPalindromeSubsequence(A))
