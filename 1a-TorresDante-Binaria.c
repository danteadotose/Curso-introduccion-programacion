 /*PROYECTO PRINCIPIOS DE PROGRAMACIÓN:
   LICENCIATURA EN CIENCIAS GENÓMICAS.
   Dante A. Torres Sepúlveda. */


#include <stdio.h>

int main()
{
/*DICCIONARIO DE VARIABLES

	-vector: Almacena los 1s y 0s que van a representar el número binario.
	-numero: EL número que convertiremos a binario.
	-x,i: Funcionan como contadores para los for- e -if-.
	-respuesta: Permite repetir el proceso si eso es lo que queremos. 

*/

int i,x,numero,respuesta;
do{
int vector[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 

// Explica para que funciona el programa y pide los datos necesarios para funcionar.
printf("Hola, este programa convertirá un número que introduzcas en su equivalente en sistema binario. Por favor, utiliza únicamente números positivos.\n");
printf("¿Qué numero quieres convertir? Maximo 32,767\n");
scanf("%d", &numero);

/*El número decimal ya está en binario dentro de la computadora, lo que hace el programa es recorrerlo y hacer un -and-
de tal forma que, si lo recorre y encuentra un 1,va a guardar en la casilla del vector un uno, de no encontrar el 1,
esa casilla del vector se quedará en 0.*/
for (x = 0; x < 15; x++){ 
	i=numero>>(x-1);
	if (i&1){
		vector[x]=1;
	}
}

//Imprime el vector en el que se guardó el numero en decimal.
for (i = 15; i > 0; i--){
	printf("%d", vector[i]); 
	}

 //Repite el proceso si eso es lo que quieres.
printf("\nSi quieres volver a correr el programa presiona 1, si quieres salir escribe 0.\n");
scanf("%d", &respuesta);
}while(respuesta==1);

return 0;

}