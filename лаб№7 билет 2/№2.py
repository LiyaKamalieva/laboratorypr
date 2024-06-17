import math

def f(x, y):
    return -y*math.cos(x) + 0.5*math.sin(2*x)

def euler_method(f, x0, y0, h, n):
    x = x0
    y = y0
    for i in range(1, n+1):
        y += h*f(x, y)
        x += h
    return y

def exact_solution(x):
    return math.sin(x) - 1 + math.exp(-math.sin(x))

x0 = 0
y0 = 0
h = 0.1
n = int(1/h)

approximate_values = [euler_method(f, x0, y0, h, i) for i in range(n+1)]
exact_values = [exact_solution(i*h) for i in range(n+1)]

for i in range(n+1):
    print(f"Approximate value at x={i*h}: {approximate_values[i]}, Exact value: {exact_values[i]}, Difference: {abs(approximate_values[i] - exact_values[i])}")
