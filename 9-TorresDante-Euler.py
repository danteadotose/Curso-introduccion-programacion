'''
Dante Torres Sepulveda.
PROYECTO COMPUTO CIENTIFICO

DICCIONARIO DE VARIABLES:

respuesta: Variable que permite correr el programa mas de una vez
funcion: Funcion que introduce el usuario y con la que se va a trabajar
error: Variable que nos permite saber la exactitud de nuestro resultado.
limit: Variable que nos permite hacer que nuestro resultado tenga la exactitud que deseamos.
result: Resultado del programa por cada iteracion
x0: Variable que guarda la x0 introducida por el usuario
y0: Variable que guarda la y0 introducida por el usuario y va cambiando en las iteraciones.
X: X a la que se desea llegar.
h: H segun la formula.
NumeroIteraciones: Numero de iteraciones que va a tener que hacer nuestro programa para llegar al resultado deseado.

'''

import sympy as sym


respuesta = 1

#  While loop que permite correr el programa mas de una vez
while respuesta == 1:

    # Se piden los datos requeridos
    x, y = sym.symbols('x y')
    print("Ingrese su funcion derivada")
    funcion = sym.sympify(input())
    result = 0
    print("Ingrese su valor para x0")
    x0 = int(input())
    print("Ingrese su valor para y0")
    y0 = int(input())
    print("Ingrese su valor para h")
    h = float(input())
    print("Ingrese el valor de X al que desee llegar")
    X = float(input())
    # NumberofTimes es el numero de veces que vamos a iterar para llegar al resultado deseado sobre X
    NumberofTimes = round(((X - x0) / h))

    for calculo in range(NumberofTimes):
        # Se saca el reultado de acuerdo con la formula
        result = y0 + (h * funcion.subs([(x, x0), (y, y0)]))
        # yn se convierte en el nuevo resultado  para las siguientes iteraciones,
        y0 = result
        # xn aumenta h hasta llegar al valor de X deseado
        x0 += h

    # Se imprimen los resultados y se pregunta si se quiere correr el programa otra vez.
    print(f"El resultado para su ecuacion es: {result}")
    print("Quieres correr el programa otra vez? Si=1 No=0?")
    respuesta = int(input())
