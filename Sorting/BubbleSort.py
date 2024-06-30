def BubbleSort(A):
    n = len(A)
    Change = True
    for i in range(0, n-1):
        if not Change:
            break
        
        Change = False
        for j in range(0, n-i-1):
            if A[j+1] < A[j]:
                A[j+1], A[j] = A[j], A[j+1]
                Change = True

if __name__ == "__main__":
    array = [i for i in range(10)]
    BubbleSort(array)