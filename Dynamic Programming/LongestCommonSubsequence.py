import numpy as np
def LongestCommonSubsequence(a, b):
    matrix = np.zeros((len(a) + 1, len(b) + 1))
    
    for i in range(0, len(a)):
        for j in range(0, len(b)):
            if a[i] == b[j]:
                matrix[i+1][j+1] = 1 + matrix[i][j]
            else:
                matrix[i+1][j+1] = max(matrix[i][j+1], matrix[i+1][j])
    
    result = ""
    i, j = len(a), len(b) 
    while i > 0 and j > 0:
        if matrix[i][j] != matrix[i-1][j]:
            result = a[i - 1] + result
            j-=1
        i-=1
    return result


if __name__ == "__main__":
    a = "ewoidsklnd"
    b = "edekl"
    print(LongestCommonSubsequence(b, a))