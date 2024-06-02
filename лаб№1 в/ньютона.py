import math

def func(x):
    return math.exp(x) * x - x - 1

def dfunc(x):
    return math.exp(x) * (x + 1)

def find(x, eps):
    iter = 0
    print("x_0 = ", x, end=" ")
    while True:
        f = func(x)
        df = dfunc(x)
        x = x - f / df
        iter += 1
        if abs(f) <= eps or iter >= 20000:
            break
    print("\nNumber of iterations is", iter)
    return x

def main():
    x0 = 0.0
    eps = 1e-6
    x = find(x0, eps)
    print("Root x =", format(x, '.16f'))
    print("Function value f(x) =", func(x))

if __name__ == "__main__":
    main()