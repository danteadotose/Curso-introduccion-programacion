 /*PROYECTO PRINCIPIOS DE PROGRAMACIÓN:
   LICENCIATURA EN CIENCIAS GENÓMICAS.
   Dante A. Torres Sepúlveda. */

#include <stdio.h>
int main()
{
/*DICCIONARIO DE VARIABLES

	-matriz: Almacena y muestra de forma gráfica las interacciones entre nodos.
	-tamano: Delimita la cantidad de nodos con los que se va a trabajar.
	-i,j,n: Funcionan como contadores para los -for- e -if-, "n" va a ser el que guarde los grados de los nodos.  

*/

int i,j,matriz[40][40],tamano,n=0;

// Explica que hace el programa, también rellena la matriz con 0s para evitar cualquier error en los pasos siguientes.
printf("Hola, a continuación generarás una matriz que represente una red no dirigida y sus conexiónes. ¿Cuantos nodos hay en tu red?\n");
scanf("%d",&tamano);
for (i = 0; i < tamano; ++i){ 
	for ( j = 0; j < tamano; ++j)
	{
		matriz[i][j]=0;
	}
}

// Como no es una red dirigida, se puede llenar únicamente el triangulo superior derecho de la matriz para conocer todas las interacciones.
for (i = 0; i < tamano; i++){ 
	for (j = i+1; j < tamano; j++){
	printf("¿El nodo %d tiene conexión con el nodo %d?", i+1, j+1);
	scanf("%d",&matriz[i][j]);
		if (matriz[i][j]==1){ // Llena los espacios faltantes con la información generada arriba.
				matriz[j][i]=1;
		}
	}
}

// Imprime la matriz y espacios para que sea más fácil de analizar visualmente.
printf("\nTu matriz es la siguiente:\n\n");
for (i = 0; i < tamano; i++){ 
	for (j =0; j < tamano; j++){
		printf("  %d", matriz[i][j]);
	}
	printf("\n"); 
}
printf("\n");

// Suma las interacciones que presenta cada nodo e imprime su grado.
for (i = 0; i < tamano; i++){ 
	n=0;
	for (j = 0; j < tamano; j++){
		if (matriz[i][j]==1){
			n++;
		}
	}
printf("El nodo %d tiene grado %d \n",i+1,n); 
}

/*for (i = 0; i < count; i++){
	for ( j = j+1; j < count; j++){
		if ()
			{
				int m++;
			}	}
}
*/
return 0;

}