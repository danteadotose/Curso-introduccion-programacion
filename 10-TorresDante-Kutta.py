'''
Dante Torres Sepulveda.
PROYECTO COMPUTO CIENTIFICO

DICCIONARIO DE VARIABLES:

respuesta: Variable que permite correr el programa mas de una vez
funcion: Funcion que introduce el usuario y con la que se va a trabajar
error: Variable que nos permite saber la exactitud de nuestro resultado.
limit: Variable que nos permite hacer que nuestro resultado tenga la exactitud que deseamos.
result: Resultado del programa por cada iteracion
x0: Variable que guarda la x0 introducida por el usuario y va cambiando en las iteraciones.
y0: Variable que guarda la y0 introducida por el usuario y va cambiando en las iteraciones.
X: X a la que se desea llegar.
h: H segun la formula.
NumeroIteraciones: Numero de iteraciones que va a tener que hacer nuestro programa para llegar al resultado deseado.
K: Todas las "Ks" guardan valores de acuerdo con la formula.


'''


import sympy as sym


respuesta = 1

# While loop que permite correr el programa mas de una vez
while respuesta == 1:

    # Se piden los datos necesarios.
    x, y = sym.symbols('x y')
    print("Ingrese su funcion derivada")
    funcion = sym.sympify(input())
    print("Ingrese su valor para x0")
    x0 = float(input())
    print("Ingrese su valor para y0")
    y0 = float(input())
    print("Ingrese su valor para h")
    h = float(input())
    print("Ingrese el valor de X al que desee llegar")
    X = float(input())
    # NumberofTimes es el numero de veces que vamos a iterar para llegar al resultado deseado sobre X
    NumeroIteraciones = round((X - x0) / h)
    result = 0

    for calculo in range(NumeroIteraciones):

        # Se sacan los resultados de K de acuerdo con la formula de Runge-Kutta
        k1 = h * funcion.subs([(x, x0), (y, y0)])
        k2 = h * funcion.subs([(x, (x0 + h / 2)), (y, (y0 + k1 / 2))])
        k3 = h * funcion.subs([(x, x0 + h / 2), (y, y0 + k2 / 2)])
        k4 = h * funcion.subs([(x, (x0 + h)), (y, (y0 + k3))])
        # Se saca el resultado sobre yn de acuerdo a la formula
        result = y0 + (1/6)*(k1 + 2*k2 + 2*k3 + k4)
        # El resultado se convierte en yn para las siguientes iteraciones
        y0 = result
        # xn aumenta h hasta llegar al valor de X deseado
        x0 += h

    # Se imprimen los resultados y se pregunta si se quiere correr el programa otra vez.
    print(f"El resultado para su ecuacion es: {result}")
    print("Quieres correr el programa otra vez? Si=1 No=0?")
    respuesta = int(input())
