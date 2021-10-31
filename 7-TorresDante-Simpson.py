'''
Dante Torres Sepulveda.
PROYECTO COMPUTO CIENTIFICO

DICCIONARIO DE VARIABLES:

respuesta: Variable que permite correr el programa mas de una vez
funcion: Funcion que introduce el usuario y con la que se va a trabajar
error: Variable que nos permite saber la exactitud de nuestro resultado.
limit: Variable que nos permite hacer que nuestro resultado tenga la exactitud que deseamos.
result: Resultado del programa por cada iteracion
b: Limite superior
a: Limite inferior
h: H segun la formula
bandas: Numero de bandas con las que queremos trabajar
yi: Variable que guarda los valores de y en las iteraciones.

'''

import sympy as sym


respuesta = 1

# While loop que permite correr el programa mas de una vez
while respuesta == 1:

    # Se piden los datoa necesarios
    x = sym.symbols('x')
    print("Ingrese su funcion")
    funcion = sym.sympify(input())
    print("Cual es su limite superior")
    b = float(input())
    print("Cual es su limite inferior")
    a = float(input())
    print("Cual es su numero de bandas")
    bandas = int(input())
    result = 0

    # Se calcula -h- de acuerdo con la formula
    h = (b-a) / bandas

    # Loop for que itera una vez mas que el numero de requerido
    for times in range(bandas + 1):
        # Se saca el yn de acuerdo a la formula
        yi = funcion.subs(x, (a + times * h))

        # Estas condionales sirven para saber si yn se va a multiplicar por 2, por 4 o por nada dependiendo de la
        # la iteracion en la que vayamos.
        if times == 0 or times == bandas:
            result += yi
        elif times/2 == int(times/2) and times != bandas + 1:
            result += 2 * yi
        elif times/2 != int(times/2) and times != bandas + 1:
            result += 4 * yi
    # Se saca el resultado final de acuerdo con la formula.
    result = (h/3) * result

    # Se imprimen los resultados y se pregunta si se quiere correr otra vez el programa
    print(f"Su resultado es: {result.evalf()}")
    print("Quieres correr el programa otra vez? Si=1 No=0?")
    respuesta = int(input())
