'''
Dante Torres Sepulveda.
PROYECTO COMPUTO CIENTIFICO

DICCIONARIO DE VARIABLES:

En este programa las variables estan muy bien documentadas dentro del codigo porque pueden llegar a ser un poco confusas.

'''

import sympy as sym


# Se inicializan todas las variables que se van a utilizar
limit = 1
# (1/k) es el numero por el que se multiplica C para sacar la primera iteracion de -I- en la formula
k = 1
# Num iteraciones nos va a decir como van a ir aumentando el numero de In**
numIteraciones = 0
# Numero de veces que se ejecuta el while, sirve para operaciones sobre I y J
count = 0
result = 0
tempResult = 0

# Todas las variables Ik(n) sirven para guardar diferentes resultados de I. Esto se hace porque la formula requiere
# resultados pasados para sacar nuevos
Ika = 0
Ika2 = 0
Ika3 = 0
IkA = 0
# Los valores de Ik(n) se van a guardar en una lista para que despues podamos acceder a ellos.
lista = [0, 0]
x = sym.symbols('x')

# Se piden los datos necesarios.
print("Ingrese su funcion")
funcion = sym.sympify(input())
print("Ingrese su limite inferior")
a = float(input())
print("Ingrese su limite superior")
b = float(input())
c = b - a
print("Ingrese de la siguiente forma cuantos decimales de error desea soportar")
print("Ejemplo; 1 -> 0.01, 2 -> 0.001, 3 -> 0.0001 ... n -> 0.(n)1")
error = float(input())

# Loop que termina una vez que las ultimas iteraciones de cada I sean iguales en el numero de decimales acordados.
while limit > error:

    # El primer resultado de J no puede ser obtenido mediante la formula general por lo que se hace una condicional
    if count == 0:
        result = (1/2) * (funcion.subs(x, a) + funcion.subs(x, b))

    # Este -else- contiene la formula general para sacarel resultado de Jn
    else:
        cons = (1/k)
        numIteraciones = (2**(count-1))
        # Cada Jn requiere un numero mayor de iteraciones, la variable numIteraciones nos ayuda a saber cuantas.
        for elemen in range(numIteraciones):
            tempResult += funcion.subs(x, (a + c * cons))
            # La variable cons empieza siendo igual a K pero va cambiando dependiendo de que -J- queramos sacar
            cons = cons + (2*(1/k))
        # Resultado de Jn
        result = tempResult + result
        # Se reinicia a 0 para no causar problemas en las siguientes iteraciones.
        tempResult = 0

    # Para sacar cada valor de In* necesitamos los valores de In y In-1. Ika = In y Ika2 = In-1
    Ika2 = Ika
    Ika = (((1 / k) * c) * result)
    # Se crea la variable IkA. Esta puede sufrir cambios sin alteral el valor de Ika2 en las siguiente iteracion
    IkA = Ika

    # Este for contiene la formula general para sacar los resultados de Inn*
    for times in range(count):
        # Cada iteracion se inserta en la lista los resultados obtenidos para Inn*
        Ika3 = ((1 / ((4 ** (times + 1)) - 1)) * (((4 ** (times + 1)) * IkA) - Ika2))
        lista.insert(0, Ika3)
        # Las siguientes variables se convierten en las iteraciones pasadas. Para entender mejor ver la formula.
        IkA = lista[times]
        Ika2 = lista[times+1]
    # El limite es el valor absoluto de la resta de los valores obtenidos en las ultimas 2 iteraciones sobre Inn*
    limit = abs(Ika2 - Ika)
    # El contador y K aumentan cada iteracion sobre el while
    count += 1
    k *= 2

# Se imprime el resultado.
print(f"Su resultado es: {round(Ika2, 5)}")
