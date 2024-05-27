parcela = 477.67
nr = 10
i = 0.0106

resultado = 0

for j in range(1, nr):
    today = parcela/(pow((1+i),(j)))
    print((pow((1+i),(j))))
    print(f"Valor do mês {j}   {today}")
    resultado += today
    print(resultado)
    print()


x = pow(1+i,24)-1
y = i * pow(1 + i, 24)

print(x)
print(y)
print(x/y)

print(parcela*x/y)
