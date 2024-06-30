def MergeSort(array, inplace = False):
    if inplace == False:
        array_copy = array.copy()
        _MergeSort(array_copy)
        return array_copy
    _MergeSort(array)

def _MergeSort(A):
    n = len(A)
    if n <= 1:
        return A
    mid = n//2
    left, l_n = A[:mid], mid
    right, r_n = A[mid:], n - mid
    _MergeSort(left)
    _MergeSort(right)

    i, j = 0, 0
    while i < l_n and j < r_n:
        if left[i] < right[j]:
            A[i+j] = left[i]
            i += 1
        else:
            A[i+j] = right[j]
            j += 1

    while i < l_n :
        A[i+j] = left[i]
        i += 1

    while j < r_n:
        A[i+j] = right[j]
        j += 1