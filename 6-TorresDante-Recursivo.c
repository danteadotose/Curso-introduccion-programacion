 /*PROYECTO PRINCIPIOS DE PROGRAMACIÓN:
   LICENCIATURA EN CIENCIAS GENÓMICAS.
   Dante A. Torres Sepúlveda. */

#include <stdio.h>

/*DICCIONARIO DE VARIABLES 

	-vector: Guarda los números con los que vamos a trabajar.
	-minimo: Marca el inicio del vector, o el inicio de la sección en la que se va a buscar.
	-mitad: Es la mitad del vector, o de la sección en la que se va a buscar.
	-final: Delimita el número de casillas que va a utilizar el vector.
	-numero: El número del que vamos a calcular su posición dentro del vector.
	-k,i: Funcionan como contadores para los -for- e -if-.

*/

int funcion(int vector[100], int minimo, int mitad, int final,int numero){

/* Esta función recursiva se encarga de hacer la búsqueda binaria. Si el número que elegiste es menor al vector en la mitad, cambia los parametros,
de forma que el final del vector se convierta en la mitad. Funciona casi igual si el numero es mayor, la diferencia es que en este caso
convierte la mitad en el inicio */
if(vector[mitad]>numero){
	final=mitad-1;
	mitad=(final-minimo)/2;
	return(funcion(vector,minimo,mitad,final,numero));
}
 if(vector[mitad]<numero){
	minimo=mitad+1;
	mitad=(final+minimo)/2;
	return(funcion(vector,minimo,mitad,final,numero));
}
else {
	return mitad+1;
	}
}

int main ()
{

//Se le informa al usuario qué hace el progra,a y se le piden los datos necesarios para funcionar.
int vector[100],numero,mitad,i,final,minimo,k;
printf("Hola, este programa te dirá la posición de un número en un conjunto de números, utilizando una función recursiva.\n");
printf("Escribe tu número\n");
scanf("%d", &numero);
printf("¿Cuántos números vas a ingresar?\n");
scanf("%d", &final);
printf("Ingresa la secuencia de números, por favor, que estén en orden ascendente:\n");
for (i = 0; i < final; i++){
	scanf("%d", &vector[i]);
}

// Aquí se delimitan los valores del vector, inicio, mitad, final. Después se llama a la función que se va a encargar de encontrar el número.
minimo=0;
mitad=(final-i+1)/2;
mitad=funcion(vector,minimo,mitad,final,numero);

// Imprime el vector completo y te dice la posición del número que elegiste. 
for (k = 0; k < final ; k++){
	printf("%d,",vector[k] );
}
printf("\nTu numero está en la posición: %d\n", mitad);


return 0;
}





