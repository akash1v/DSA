def TimSort(array, inplace = False):
    if inplace == False:
        array_copy = array.copy()
        _TimSort(array_copy)
        return array_copy
    _TimSort(array)

def _TimSort(A):
    n = len(A)
    if n < 65:                      #insertion sort
        for i in range(1, n):
            key = A[i]
            j = i - 1
            while j >= 0 and key < A[j]:
                A[j + 1] = A[j]
                j -= 1
            A[j + 1] = key
    else:                           #merge sort
        mid = n//2
        left, l_n = A[:mid], mid
        right, r_n = A[mid:], n - mid
        _TimSort(left)
        _TimSort(right)

        i, j = 0, 0
        while i < l_n and j < r_n:
            if left[i] < right[j]:
                A[i+j] = left[i]
                i += 1
            else:
                A[i+j] = right[j]
                j += 1

        while i < l_n:
            A[i+j] = left[i]
            i += 1

        while j < r_n:
            A[i+j] = right[j]
            j += 1