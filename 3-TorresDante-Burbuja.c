 /*PROYECTO PRINCIPIOS DE PROGRAMACIÓN:
   LICENCIATURA EN CIENCIAS GENÓMICAS.
   Dante A. Torres Sepúlveda. */

 #include <stdio.h>
int main()
{
/*DICIONARIO DE VARIABLES:

	-i,k: Funcionan como contadores dentro de los -for-
	-aux: Funciona para que no se pierda información al momento de intercambiar posiciones dentro del vector.
	-tamano: Delimita la cantidad de casillas del vector que van a ser utilizadas.
	-vector: Almacena los números que vamos a ordenar
	-respuesta: Permite repetir el procedimiento si eso es lo que se desea.

*/

int respuesta;
long int i, aux=0, k, tamano,vector[10000];

do {

//Se le informa al usuario qué hace el progra,a y se le piden los datos necesarios para funcionar.
printf("Hola, este programa está diseñado para ordenar de menor a mayor una serie de números que introduzcas. El rango en el que puede trabajar es de -20,000 a 20,000. Después de que ingreses cada número presiona enter.\n ¿Cuántos números quieres ingresar? Máximo 10,000 \n");
scanf("%ld", &tamano); 
printf("Ingresa un número y después presiona enter\n");
// Este -for- lee números proporcionados desde el teclado. También delimita el valor que puedan obtener estos.
for (i = 0; i < tamano; i++){ 
	scanf("%ld",&vector[i]);
	if (vector[i]>20000||vector[i]<-20000){
		printf("Ingresaste un número incorrecto, por favor, sigue las especificaciones.\n");
		return 0;
	}
}

/*Este -for- recorre el vector. Si encuentra que en una casilla hay un número más alto que en la casilla siguiente, los cambia de lugar.
 Básicamente, ordena de menor a mayor*/
printf("Tus números en orden acendente son:\n");
for (k = 0; k < tamano-1; k++){ 
	for ( i= 0; i < tamano-1 ; i++){
		if (vector[i]>vector[i+1]){
			aux=vector[i+1];
			vector[i+1]=vector[i];
			vector[i]=aux;
		}
	}
}

//Imprime el vector ordenado.
for (k = 0; k < tamano; k++){ 
	printf("%ld\n",vector[k] );
}

// Repite el proceso si eso es lo que quieres.
printf("Si quieres volver a correr el programa presiona 1, si quieres salir escribe 0.\n"); 
scanf("%d", &respuesta);

} while (respuesta==1);

return 0;
}

