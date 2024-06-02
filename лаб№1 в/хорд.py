import math

def func(x):
    return math.pow(math.e, x)* x - x - 1

def find(x0, x1, eps):
    iter = 0
    x_next = 0
    tmp = 0
    
    while abs(x_next - x1) > eps and iter < 20000:
        tmp = x_next
        x_next = x1 - func(x1) * (x0 - x1) / (func(x0) - func(x1))
        x0 = x1
        x1 = tmp
        iter += 1
    
    print("\nNumber of iterations is", iter, ".")
    
    return x_next

if __name__ == "__main__":
    x0 = float(input("a = "))
    x1 = float(input("b = "))
    eps = math.pow(10, -6)
    x = find(x0, x1, eps)
    print("Root x =", format(x, '.16f'))
    print("Function value f(x) =", func(x))