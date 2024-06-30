def BinarySearch(array, key):
    return _BinarySearch(array, 0, len(array) - 1, key)

def _BinarySearch(arr, left, right, key):
    
    if right < left:
        return None
    mid = (right + left)

    if key == arr[mid]:
        return mid
    elif key < arr[mid]:
        return _BinarySearch(arr, left, mid, key)
    else:
        return _BinarySearch(arr, mid, right, key)
