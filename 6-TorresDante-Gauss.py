'''
Dante Torres Sepulveda.
PROYECTO COMPUTO CIENTIFICO

DICCIONARIO DE VARIABLES:

funcion: Funcion que introduce el usuario y con la que se va a trabajar
error: Variable que nos permite saber la exactitud de nuestro resultado.
limit: Variable que nos permite hacer que nuestro resultado tenga la exactitud que deseamos.
result: Resultado del programa por cada iteracion
aproximaciones: Variable que guarda el valor de las aproximaciones que vamos haceindo.
variables: Variables que vamos a utilizar.
ecuacion: Ecuaciones que va a tener nuestro sistema.
letras: Variable que permite crear los simbolos con los que funciona el programa.
ListSumas: Lista que guarda valores que permiten ver si nuestro resultado es tan exacto como lo queremos
EcuacionTemporal: Variable temporal

'''

import sympy as sym


def guardar_aprox(variables, aproximaciones):
    """
    :param variables: variables que contiene nuestro sistema de ecuaciones
    :param aproximaciones: regresa una lista con las aproximaciones que el usuario indique. En caso de no saber,
    estas deberan estar igualadas a 0.
    :return:
    """
    for element in variables:
        print (f"Cual es el valor aproximado de {element}. Si no lo sabe, asuma que es 0")
        aproximaciones.append(float(input()))
        # Se crean los simbolos que se utilizaran en el codigo
        letras.append(sym.symbols(element))


def guardar_ecuaciones (variables, ecuacion):
    """
    :param variables: variables que contiene nuestro sistema de ecuaciones
    :param ecuacion: lista con las ecuaciones de nuetro sistema
    :return: Regresa el numero de ecuaciones
    """
    num = 0
    for literal in variables:
        print(f"Cual es su ecuacion #{num + 1}. Por favor, que este igualada a la variable {literal} y que esten acomodadas de manera diagonal.")
        ecuacion.append(sym.sympify(input()))
        num += 1
    return num


# Listas y variables que se van a utilizar en el programa
ecuacion = []
aproximaciones = []
letras = []
result = 0
ListaSumas = []
count = 0


# Se guardan los datos necesarios
print("Cuales son las variables de su sistema? Por favor, separe cada una con una coma.")
variables = input().split(',')
guardar_aprox(variables, aproximaciones)
numero = guardar_ecuaciones(variables, ecuacion)
print("Ingrese de la siguiente forma cuantos decimales de error desea soportar")
print("Ejemplo; 1 -> 0.01, 2 -> 0.001, 3 -> 0.0001 ... n -> 0.(n)1")
error = float(input())
limit = 1

# Loop que para una vez que encontrenos el resultado
while limit > error:
    # Se inserta en una lista el resultado de las aproximaciones antes y despues de hacer los calculos
    # Por motivos de comodidad iempre se insertaran en el indice 0 y 1.
    ListaSumas.insert(0, sum(aproximaciones))

    for times in range(numero):
        # Se crea una variable a la que se le asigna cada una de las ecuaciones dependiendo de la iteracion
        EcuacionTemporal = ecuacion[times]
        for element in range(numero):
            # Se obtiene el resultado determinado por la formula de Gauss
            result = EcuacionTemporal.subs(variables[element], aproximaciones[element])
            EcuacionTemporal = result

        # Se actualiza la lista de las aproximaciones con los resultados obtenidos
        aproximaciones[times] = result.evalf()
        # Se reinicia el resultado para no tener problemas en las siguientes iteraciones
        result = 0

    # Se aniade a la lista la suma de los valores obtenidos despues de aplicar la formula
    ListaSumas.insert(1, sum(aproximaciones))
    # Se comparan los indices 0 y 1 de la lista. Si el valor absoluto de la resta de los resultados es menor al error,
    # el loop ya no entrara otra vez.
    limit = abs(ListaSumas[0]-ListaSumas[1])
    count += 1
    if count > 100:
        # Si el loop se repite mas de 100 veces, asumimos que no hay convergencia.
        print("Su sistema de ecuaciones no tiene una sola solucion")
        quit()

# Se imprimen los resultados encontrados para cada una de las variables
print("Sus valores son: ")
for element in range(numero):
    print(f"   {variables[element]} = {round(aproximaciones[element],6)}")

