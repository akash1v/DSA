def Karatsuba(x, y):
    if x<10 or y<10:
        return x*y
    n = max(len(str(x)), len(str(y)))
    n2 = n//2
    t = 10**n2

    a = x//t
    b = x%t
    c = y//t
    d = y%t

    ac = Karatsuba(a, c)
    bd = Karatsuba(b, d)
    ad_bc = Karatsuba(a + b, c + d) - (ac + bd)
    return ac*t*t + ad_bc*t + bd