# №2 даны три вектора в пространстве координаты которых определены случайным образом. найти их длины, найти попарно углы между ними, найти попарно сумму и разность векторов, выяснить вопрос о том, что они лежат в одной плоскости, есть ли параллельные среди них или нет, найти смешанное произведение векторов
import numpy as np


v1 = np.random.rand(3)
v2 = np.random.rand(3)
v3 = np.random.rand(3)

print("Вектор v1:", v1)
print("Вектор v2:", v2)
print("Вектор v3:", v3)

len_v1 = np.linalg.norm(v1)
len_v2 = np.linalg.norm(v2)
len_v3 = np.linalg.norm(v3)

print("Длина вектора v1:", len_v1)
print("Длина вектора v2:", len_v2)
print("Длина вектора v3:", len_v3)
# Нахождение углов между векторами
angle_v1_v2 = np.arccos(np.dot(v1, v2) / (np.linalg.norm(v1) * np.linalg.norm(v2))) #скалярное произведение, это значение делится на произведение длин векторов v1 и v2
angle_v1_v3 = np.arccos(np.dot(v1, v3) / (np.linalg.norm(v1) * np.linalg.norm(v3)))
angle_v2_v3 = np.arccos(np.dot(v2, v3) / (np.linalg.norm(v2) * np.linalg.norm(v3)))

print("Угол между векторами v1 и v2:", np.degrees(angle_v1_v2))
print("Угол между векторами v1 и v3:", np.degrees(angle_v1_v3))
print("Угол между векторами v2 и v3:", np.degrees(angle_v2_v3))
# Сумма и разность векторов
sum_v1_v2 = v1 + v2
diff_v1_v2 = v1 - v2
sum_v1_v3 = v1 + v3
diff_v1_v3 = v1 - v3
sum_v2_v3 = v2 + v3
diff_v2_v3 = v2 - v3

print("Сумма векторов v1 и v2:", sum_v1_v2)
print("Разность векторов v1 и v2:", diff_v1_v2)
print("Сумма векторов v1 и v3:", sum_v1_v3)
print("Разность векторов v1 и v3:", diff_v1_v3)
print("Сумма векторов v2 и v3:", sum_v2_v3)
print("Разность векторов v2 и v3:", diff_v2_v3)
# Смешанное произведение векторов
mixed_product = np.dot(np.cross(v1, v2), v3)

if mixed_product == 0:
    print("Вектора лежат в одной плоскости")
else:
    print("Вектора не  лежат в одной плоскости")
