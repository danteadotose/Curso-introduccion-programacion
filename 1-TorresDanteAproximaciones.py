'''
Dante Torres Sepulveda.
PROYECTO COMPUTO CIENTIFICO

DICCIONARIO DE VARIABLES:

intervalo1: Intervalo entre el que se va a buscar la raiz
intervalo2: Intervalo entre el que se va a buscar la raiz
diccionario: Diccionario donde se van a guardar las posibles raices.
intervalos: Permite guardar el numero de raices posibles que deseamos.
num: Resultado de sustituir los intervalos en la funcion.
respuesta: Variable que permite correr el programa mas de una vez
funcion: Funcion que introduce el usuario y con la que se va a trabajar
despeje: Despeje que introduce el usuario
error: Variable que nos permite saber la exactitud de nuestro resultado.
limit: Variable que nos permite hacer que nuestro resultado tenga la exactitud que deseamos.
result: Resultado del programa por cada iteracion
aprox: Variable que guarda el resultado final.

'''

import sympy as sym


def localizar_raiz(funcion):
    """
    :param funcion: Funcion proporcionada por el usuario
    :return: diccionario con las posibles raices
    Esta funcion localiza y devuelve las posibles raices al usuario.
    """
    print("Entre que intervalos quieres buscar la raiz? Introduzca numeros enteros y el mas chico primero.")
    intervalo1 = int(input())
    intervalo2 = int(input())
    diccionario = {}
    intervalos = []
    for num in range(intervalo2 - intervalo1):
        intervalos.append(intervalo1)
        intervalo1 += 1
    for element in intervalos:
        num = function.subs(x, element)
        diccionario[element] = round(sym.re(num).evalf(), 2)
    return diccionario


respuesta = 1

# While loop que permite correr el programa mas de una vez
while respuesta == 1:

    # Se recolectan todos los datos necesarios.
    x = sym.symbols('x')
    print("Cual es su funcion?")
    function = sym.sympify(input())
    print("Cual es su despeje")
    despeje = sym.sympify(input())
    print(localizar_raiz(function))
    print("Elija el intervalo medio que quiera usar como aproximacion?")
    aprox = float(input())
    print("Ingrese de la siguiente forma cuantos decimales de error desea soportar")
    print("Ejemplo; 1 -> 0.01, 2 -> 0.001, 3 -> 0.0001 ... n -> 0.(n)1")
    error = float(input())
    limit = float(1)

    # El contador permite que nos salgamos del loop si no encuentra una posible convergencia.
    count = 0
    # Loop que para una vez que encontremos el resultado deseado.
    while limit > error:
        result = despeje.subs(x, aprox)
        # El limite es el valor absoluto de la resta del resultado y la aproximacion, cada vez se hace menor.
        limit = sym.Abs(result - aprox)
        # El nuevo resultado se convierte en la aproximacion
        aprox = result
        count += 1
        if count > 100:
            # Si el loop se repite mas de 100 veces, asumimos que no hay convergencia.
            print("El despeje que eligio no converge, intentelo otra vez con otro")
            quit()
    # Se imprime el resultado y se pregunta si se quiere correr otra vez.
    print(f"Su resultado es {aprox}")
    print("Quieres correr el programa otra vez? Si=1 No=0?")
    respuesta = int(input())
