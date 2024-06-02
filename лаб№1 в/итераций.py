import math

def func(x):
    return math.exp(x) * x - x - 1

def find(x, eps):
    x_1 = x
    x_2 = x
    iter = 0
    while True:
        x_1 = x_2
        x_2 = 1 + x_1 / math.exp(x_1)
        iter += 1
        if abs(x_2 - x_1) <= eps or iter >= 20:
            break
    print(f"Number of iterations is {iter}")
    return x_2

def main():
    x0 = 1.5
    eps = 1e-6
    root = find(x0, eps)
    print(f"Root x = {root}")
    print(f"Function value f(x) = {func(root)}")

if __name__ == "__main__":
    main()