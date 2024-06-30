def Power(X, n):
    if n == 0:
        return 1
    s1 = Power(X, n//2)
    s1 = s1*s1
    if n%2 == 0:
        return s1
    return s1*X