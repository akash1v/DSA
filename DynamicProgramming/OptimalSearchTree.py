import numpy as np

def OptimalSearchTree(pi, qi = []):#successful keys, unsuccessful keys

    n = len(qi)

    dm = np.zeros((n,n))    #data matrix
    sm = np.zeros((n,n))    #split matrix or root node matrix
 
    for c in range(1, n):
        for i in range(0, n-c):
            j = i + c

            weight = qi[j]
            for k in range(i, j):
                weight += qi[k]
                weight += pi[k]
            
            cost, split_at = float('inf'), 0
            for k in range(i, j):
                temp_cost = dm[i][k] + dm[k+1][j] + weight
                if temp_cost < cost:
                    cost = temp_cost
                    split_at = k+1

            dm[i][j] = cost
            sm[i][j] = split_at

    return dm, sm

if __name__ == "__main__":
    successful = [4,2,6,3]
    unsuccessful = [2,3,1,1,1]
    dm, sm = OptimalSearchTree(successful, unsuccessful)
    print(dm)
    print()
    print(sm)