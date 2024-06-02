import math

def func(x):
    return math.exp(x) * x - x - 1

def main():
    iter = 0
    eps = 1e-6
    a = -2.0
    b = 2.0
    t = 0
    f1 = func(a)
    f2 = 0
    x = 0

    while abs(b - a) > eps:
        f1 = func(a)
        t = (a + b) / 2.0
        f2 = func(t)
        if f1 * f2 <= 0:
            b = t
        else:
            a = t
        iter += 1

    x = (a + b) / 2.0
    f1 = func(x)

    if abs(f1) <= eps:
        print(f"\nThe root of the equation with error eps = {eps} is x = {x}")
        print(f"Function value f(x) = {func(x)}")
        print(f"Number of iterations is {iter}")
    else:
        print("On this segment the equation has no roots!!!")

if __name__ == "__main__": main()