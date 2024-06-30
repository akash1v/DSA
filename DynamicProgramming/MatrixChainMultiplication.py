import numpy as np
def MatrixChanMultiplication(d):#dimensions
    n = len(d) - 1              #no of matrices
    dm = np.zeros((n, n))       #data matrix
    sm = np.zeros((n, n))       #split matrix
    
    for c in range(1, n):
        for i in range(0, n-c):

            j = i + c
            cost, split_at = float('inf'), 0
            for k in range(i, j):

                temp_cost = dm[i][k] + dm[k+1][j] + d[i] * d[k+1] * d[j+1]

                if temp_cost < cost:
                    cost = temp_cost
                    split_at = k+1-i

            dm[i][j] = cost    
            sm[i][j] = split_at   

    return dm, sm

if __name__ == "__main__":
    dimensions = [10, 40, 1, 5, 9, 20]
    dm, sm = MatrixChanMultiplication(dimensions)
    print(dm)
    print()
    print(sm)