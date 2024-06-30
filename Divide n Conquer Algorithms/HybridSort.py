def HybridSort(array, inplace = False):
    if inplace == False:
        array_copy = array.copy()
        _HybridSort(array_copy, 0, len(array_copy) - 1)
        return array_copy
    _HybridSort(array, 0, len(array) - 1)

def _HybridSort(array, start, end):
    if end <= start:
        return

    if end - start <64:                        #insertion sort
        for i in range(start + 1, end + 1):
            key = array[i]
            j = i - 1
            while j >= start and key < array[j]:
                array[j + 1] = array[j]
                j -= 1
            array[j + 1] = key  
    else:                                       #quick sort
        pivot = array[end]
        i = start
        for j in range(start, end):
            if array[j] <= pivot:
                array[i], array[j] = array[j], array[i]
                i = i + 1
        array[i], array[end] = array[end], array[i]
        _HybridSort(array, start, i-1)
        _HybridSort(array, i+1, end)