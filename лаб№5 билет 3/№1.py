import numpy as np


x = np.array([-1.0, 0.0, 1.0, 2.0, 3.0])
y = np.array([-0.5, 0.0, 0.5, 0.86603, 1.0])


dy_dx = np.gradient(y, x)


d2y_dx2 = np.gradient(dy_dx, x)


index = np.where(x==1.0)[0][0]


print(f"Первая производная в точке x=1.0: {dy_dx[index]}")
print(f"Вторая производная в точке x=1.0: {d2y_dx2[index]}")