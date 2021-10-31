'''
Dante Torres Sepulveda.
PROYECTO COMPUTO CIENTIFICO

DICCIONARIO DE VARIABLES:

respuesta: Variable que permite correr el programa mas de una vez
funcion: Funcion que introduce el usuario y con la que se va a trabajar
error: Variable que nos permite saber la exactitud de nuestro resultado.
limit: Variable que nos permite hacer que nuestro resultado tenga la exactitud que deseamos.
result: Resultado del programa por cada iteracion
aprox: Variable que guarda el resultado final.
lista: Lista donde se guardan los datos de las variables x,y.
num_datos: Numero de datos que introduce el usuario.
xi: Datos de la variable x.
yi: Datos de la variable y.
CalculoArriba: Calculo de arriba de la ecuacion segun la formula.
CalculoAbajo: Calculo de abajo de la ecuacion segun la formula.
result2: Resultado despues de sustituir la x deseada en el polinomio.
X: x que deseamos interpolar.

'''

import sympy as sym


def crear_lista (numero_datos):
    """
    :param numero_datos: Nos dice el numero de datos que tenemos para las variables.
    :return: Regresa una lista con los datos para cada variable
    """
    lista = []
    for datos in range(num_datos):
        lista.append(float(input()))
    return lista


respuesta = 1

# While loop que permite correr el programa mas de una vez
while respuesta == 1:

    # Se recolectan los datos necesarios.
    x = sym.symbols('x')
    print("Cuantos datos para x,y tiene? ")
    num_datos = int(input())

    # Se llama a la funcion y se obtienen los valores tanto para x, como para y.
    print("Ingrese uno por uno sus valores para x, cada que escriba uno, ponga enter")
    xi = crear_lista(num_datos)
    print("Ingrese uno por uno sus valores para y, cada que escriba uno, ponga enter")
    yi = crear_lista(num_datos)

    # Variables que se utilizan en la formula
    CalculoAbajo = 1
    result = 0
    CalculoArriba = 1
    counter = 1

    # Cada -for- se comporta como la sumatoria presente en la formula. Uno es sobre -i- y el otro sobre -j-
    for element in range(num_datos):
        for times in range(num_datos):
            # La formula nos indica que -i- y -j- no pueden ser iguales, este -if- se asegura de eso
            if xi[element] != xi[times]:
                CalculoArriba *= (x - xi[times])
                CalculoAbajo *= (xi[element] - xi[times])
            # En caso de que -j- e -i- sea iguales, no se hinguna operacion y se salta a la siguiente iteracion
            else:
                pass
        # Asi se obtiene el resultado en la formula
        result += ((CalculoArriba / CalculoAbajo) * yi[element])
        # Estas variables se reinician para no alterar los resultados de las siguientes iteraciones
        CalculoArriba = 1
        CalculoAbajo = 1
        # Todoo este loop nos arroja como resultado un polinomio general
        result = sym.sympify(sym.simplify(result))
    print(f"Su polinomio es: {result}")

    # En el caso de que se quiera interpolar, se recolecta el valor deseado
    print("Ingrese el valor de X para el que desea interpolar")
    X = float(input())
    # Se sustituye la x que queremos interpolar en el polinomio previamente obtenido
    result2 = result.subs(x, X)
    # Se imprime el resultado y se pregunta si se quiere correr otra vez.
    print(f"El resultado de su x interpolada es {round(result2, 4)}:")
    print("Quieres correr el programa otra vez? Si=1 No=0?")
    respuesta = int(input())
