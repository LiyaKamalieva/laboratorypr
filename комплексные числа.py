from numpy import complex

z1 = complex(2.0, 1.0) # комплексное число, составленное из двух элементов типа double (действительной и мнимой части)
z2 = complex(2.0, -2.0)

print("z1 = 2 + i")
print("z2 = 2 - 2i")

sum = z1 + z2
print("Sum:", sum)

diff = z1 - z2
print("Difference:", diff)

prod = z1 * z2
print("Product:", prod)

div = z1 / z2
print("Division:", div)