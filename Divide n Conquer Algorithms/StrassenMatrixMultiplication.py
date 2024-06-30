import numpy as np

def StrassenMatrixMultiplication(A, B):
    if len(A) == 1:
        return A*B
    
    if len(A)% 2 != 0:
        A = np.pad(A, ((0, 1), (0, 1)), mode='constant')
        B = np.pad(B, ((0, 1), (0, 1)), mode='constant')

    A11, A12, A21, A22 = Split(A)
    B11, B12, B21, B22 = Split(B)
    
    P = StrassenMatrixMultiplication((A11 + A22), (B11 + B22))
    Q = StrassenMatrixMultiplication((A11 + A12), B22)
    R = StrassenMatrixMultiplication((A22 + A21), B11)
    S = StrassenMatrixMultiplication(A22, (B21 - B11))
    T = StrassenMatrixMultiplication(A11, (B12 - B22))
    U = StrassenMatrixMultiplication((A12 - A22), (B22 + B21))
    V = StrassenMatrixMultiplication((A21 - A11), (B11 + B12))

    C11 = P-Q+S+U
    C12 = Q + T
    C21 = R + S
    C22 = P-R+T+V    
    return Merge(C11, C12, C21, C22)


def Split(M):
    mid = len(M)//2    
    M11 = M[:mid, :mid]
    M12 = M[:mid, mid:]
    M21 = M[mid:, :mid]
    M22 = M[mid:, mid:]
    return M11, M12, M21, M22

def Merge(M11, M12, M21, M22):
    M1 = np.hstack((M11, M12))
    M2 = np.hstack((M21, M22))
    M = np.vstack((M1, M2))
    return M