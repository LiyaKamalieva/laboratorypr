import sympy as sp

#дано уравнение эллиптического цилиндра, плоскости, прямой и координата точки в пространстве, параметры которых определены случайным образом. исследовать вопрос о том пересекает ли плоскость или прямая заданный эллиптический цилиндр, принадлежит ли заданная точка эллиптическому цилиндру
x, y, z = sp.symbols('x y z')
a, b, c = sp.symbols('a b c')


elliptic_cylinder_eq = x**2/a**2 + y**2/b**2 - 1
plane_eq = z - c
line_eq = x - y - z
point = (1, 2, 3)
intersection_plane = sp.solve([elliptic_cylinder_eq, plane_eq], (x, y, z))

if len(intersection_plane) > 0:
    print("Плоскость пересекает эллиптический цилиндр")
else:
    print("Плоскость не пересекает эллиптический цилиндр")


elliptic_cylinder_surface = elliptic_cylinder_eq.subs({z: point[2]})
point_belongs_to_cylinder = elliptic_cylinder_surface.subs({x: point[0], y: point[1]})

if point_belongs_to_cylinder == 0:
    print("Точка принадлежит эллиптическому цилиндру")
else:
    print("Точка не принадлежит эллиптическому цилиндру")
