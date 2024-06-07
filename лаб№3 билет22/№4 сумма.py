from math import sin


def func(k, x):
    return ((-1)**k) / (sin(k*x) + 22 + k**2)

def func_series(x, eps):
    s = 0
    k = 1
    while True:
        current_value = func(k, x)
        s += current_value
        k += 1
        if abs(current_value) < eps:
            break
    return s


x = float(input('Enter x value: '))


eps = 1e-6


result = func_series(x, eps)
print('Сумма функционального ряда с точностью 10^(-6):', result)
