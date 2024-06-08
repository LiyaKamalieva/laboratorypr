import numpy as np


A = np.array([[-10, -1, 3],
              [8, 7, 2],
              [6, 6, 2]])
B = np.array([-1, 0, 2])


def kramer_method(A, B):
    det_A = np.linalg.det(A)
    if det_A == 0:
        return None
    n = len(B)
    solutions = []
    for i in range(n):
        A_i = A.copy()
        A_i[:, i] = B
        det_A_i = np.linalg.det(A_i)
        solutions.append(det_A_i / det_A)
    return solutions

kramer_solutions = kramer_method(A, B)
print("Решения методом Крамера:", kramer_solutions)


def jacobi_method(A, B, max_iters=100, tol=1e-6):
    n = len(B)
    x = np.zeros(n)
    x_new = np.zeros(n)
    for _ in range(max_iters):
        for i in range(n):
            x_new[i] = (B[i] - np.dot(A[i, :i], x[:i]) - np.dot(A[i, i+1:], x[i+1:])) / A[i, i]        
        if np.linalg.norm(x_new - x) < tol:
            return x_new
        x = x_new.copy()
    return None

jacobi_solutions = jacobi_method(A, B)
print("Решения методом Якоби:", jacobi_solutions)
