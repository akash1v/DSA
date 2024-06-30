def QuickSort(array, inplace = False):

    if inplace == False:
        array_copy = array.copy()
        _QuickSort(array_copy, 0, len(array_copy) - 1)
        return array_copy
    _QuickSort(array, 0, len(array) - 1)

def _QuickSort(A, low, high):
    if high - low < 1:
        return
    i = low
    for j in range(low, high):
        if A[j] < A[high]:
            A[i], A[j] = A[j], A[i]
            i += 1
    A[i], A[high] = A[high], A[i]
    
    _QuickSort(A, low, i-1)
    _QuickSort(A, i+1, high)