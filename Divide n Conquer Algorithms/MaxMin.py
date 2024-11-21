def MaxMin(list, a, b):

    if a == b:
        return list[a], list[a]
    
    if a+1 == b:
        if list[a] > list[b]:
            return list[a], list[b]
        return list[b], list[a]

    mid = (b+a)/2
    l_max, l_min = MaxMin(list, a, mid)
    r_max, r_min = MaxMin(list, mid+1, b)

    if l_max > r_max:
        max = l_max
    else:
        max = r_max
    
    if l_min < r_min:
        min = l_min
    else:
        min = r_min
    
    return max, min