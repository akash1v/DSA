def BitwiseMultiplication(x,y):
    result = 0
    while y:
        if y & 1:
            result += x
        x <<= 1
        y >>= 1
    return result