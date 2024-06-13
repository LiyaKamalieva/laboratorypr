import sympy as sp

# определяем переменные
x = sp.Symbol('x')
y = sp.Symbol('y')

# определяем функцию
f = 7*x**2 + 2*x*y + 5*y**2 + x - 10*y

# вычисляем градиент функции f(x, y)
grad = [f.diff(var) for var in (x, y)]

# начальные значения переменных
x_val = 0
y_val = 0

# learning rate
alpha = 0.01

# число итераций
num_iterations = 100

# метод наискорейшего спуска
for i in range(num_iterations):
    # вычисляем значение градиента в текущей точке
    grad_val = [g.evalf(subs={x: x_val, y: y_val}) for g in grad]
    
    # обновляем значения переменных
    x_val = x_val - alpha * grad_val[0]
    y_val = y_val - alpha * grad_val[1]

# выводим оптимальные значения переменных
print(f"Optimal value x: {x_val}")
print(f"Optimal value y: {y_val}")
