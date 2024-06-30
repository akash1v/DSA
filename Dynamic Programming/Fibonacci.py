import numpy as np

def Fibonacci(a):
    if a < 0:
        return None
    if a == 0 :
        return 0
    elif a == 1:
        return 1
    else:
        dm = np.full(a, -1)
        dm[0] = 0
        dm[1] = 1
        return _Fibonacci(a, dm)    

def _Fibonacci(a, dm):
    if dm[a-2] == -1:
        dm[a-2] = _Fibonacci(a - 2, dm)
    if dm[a-1] == -1:
        dm[a-1] = dm[a-2] + dm[a-3]
    return dm[a - 1] + dm[a - 2]

if __name__ == "__main__":
    k = 9
    print(f"Fibonacci of {k} is : {Fibonacci(k)}")