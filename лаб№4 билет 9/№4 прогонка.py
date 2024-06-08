import numpy

def Metod_Progonki(A, B):
    k1 = -A[0, 1]
    m1 = B[0]
    k2 = -A[A.shape[0] - 1, A.shape[1] - 2]
    m2 = B[B.shape[0] - 1]
    alfa = k1
    beta = m1
    
    c = 2
    a = 0
    b = 1
    alf = [alfa]
    bet = [beta]
    
    for i in range(1, A.shape[0] - 1):
        beta = (B[i] - A[i, a] * beta) / (A[i, a] * alfa + A[i, b])
        alfa = -A[i, c] / (A[i, a] * alfa + A[i, b])
        a += 1
        b += 1
        c += 1
        alf.append(alfa)
        bet.append(beta)
    
    y = (k2 * beta + m2) / (1 - k2 * alfa)
    otv = [y]
    
    for i in range(len(alf) - 1, -1, -1):
        y = alf[i] * y + bet[i]
        otv.append(y)
    
    otvet = []
    for i in reversed(otv):
        otvet.append(i)
    
    return otvet

A = numpy.array([[8, -4, 0, 0, 0],
                 [-2, 12, -7, 0, 0],
                 [0, 2, -9, 1, 0],
                 [0, 0, -8, 0, 17],
                 [0, 0, 0, 13, -7]])

B = numpy.array([32, 15, -10, 133, -76])

print(A)
print(B)
print(Metod_Progonki(A, B))
