/*
Dante Torres Sepulveda. 
PROYECTO DE COMPUTO CIENTIFICO

DICCIONARIO DE VARIABLES:

NumX: Numero de x^n que debe tener nuestra matriz.
Contador: Variable que sirve como contador
Grado: Grado del polinomio
NumDatos: Alto que va a tener la matriz de datos
LargoMat: Largo que va a tener la matriz de datos.
VariableTemporal: Variable temporal auxiliar.
VariableAuxiliar: Variable temporal auxiliar.
EcuacionAuxiliar: Variable temporal auxiliar.
MatrizSuma: Matriz que guarda las sumatorias
MatrizDatos: Matriz que guarda los datos.
ListaSumatoria: Lista que guarda las sumatorias de nuestros datos.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Funcion que nos ayuda a borrar la memoria que reservamos. Como es una matriz, el for se usa para evitar memory leaks.
void BorrarMatriz(float **matriz, int LargoMat) {

	for(int i = 0; i < LargoMat; i++)
		free((float*)matriz[i]);

	free
	(matriz);
}


int main(){

	int i, j, n = 0, NumX, Contador = 0, Grado, NumDatos, LargoMat, AltoMat, VariableTemporal;
	float VariableAuxiliar, EcuacionAuxiliar, **MatrizSuma = NULL, **MatrizDatos = NULL, *ListaSumatoria = NULL;
	printf("Cual es el grado de su polinomio?\n");
	scanf("%i", &Grado);
	printf("Cuantos datos para x/y tiene?\n");
	scanf("%i", &NumDatos);
	// Se calcula el largo que debera tener la matriz de acuerdo con el grado del polinomio.
	LargoMat = ((2*Grado) + (Grado + 1));
	// Se calcula el numero de x^n que debera tener la matriz de acuerdo al grado del polinomio.
	NumX= ((Grado * 2)- 1);


	// Se reserva memoria dinamica para la matriz de datos. NumDatos x LargoMatriz
	MatrizDatos = (float**)malloc(NumDatos * sizeof(float*));
	for (i = 0; i < NumDatos; i++){
		MatrizDatos[i] = (float*)malloc(LargoMat * sizeof(float));
	}

	// Este for sirve para rellenar la matriz de acuerdo a lo indicado por el usuario.
	for (i = 0; i < NumDatos; i++){
		for (j = 0; j < LargoMat; j++){
			if (j == 0){
				// Los valores de 'x', 'y' siempre van a estar en la columna 0, y 1. Esto facilita acceder a ellos despues.
				printf("Cual es su valor para X%i?\n", i+1);
				scanf("%f", &MatrizDatos[i][1]);
				printf("Cual es su valor para Y%i?\n", i+1);
				scanf("%f", &MatrizDatos[i][0]);
			}
 
			if (j > 1){
				if (Contador != NumX){
					// Llenamos primero las columnas con 'x^n'
					MatrizDatos[i][j] = pow(MatrizDatos[i][1], (j));
					Contador ++;
				}
					else {
						n ++;
						//Despues llenamos las columnas con 'x^n * y'
						MatrizDatos[i][j] = (MatrizDatos[i][0] * pow(MatrizDatos[i][1], (n)));
					}
			}
		}
		// La variable Contador nos ayuuda a que las columnas que llebenos con x^n sean las mismas que en NumX que tenemos.
		Contador = 0;
		// La variable n nos ayuda a rellenar las columnas de 'x^n * y' con la 'n' correspondiete.
		n = 0;
	}

	// Se crea una lista que contiene las sumatorias de todas las columnas de la matriz de datos.
    ListaSumatoria = (float*)malloc(LargoMat * sizeof(float));
	for (i = 0; i < LargoMat; i++){
	    ListaSumatoria[i] = 0;
		for (j = 0; j < NumDatos; j++){
		    ListaSumatoria[i] += MatrizDatos[j][i];
		}
	}


	//Se reserva memoria para la matriz de sumatorias. (Grado + 2) x  (Grado + 1)
	MatrizSuma = (float**)malloc((Grado + 2) * sizeof(float*));
	for (i = 0; i < (Grado + 2); i++){
		MatrizSuma[i] = (float*)malloc((Grado + 1) * sizeof(float));
	}


	/* Este for rellena la matriz con los datos de la lista de sumatorias. Como 'y' siempre esta en la columna 0, 
	la lista de sumatorias la recorremos con (j+1). Los resultados de y siempre van al final de las filas. */
	for (i = 0; i < (Grado + 1); i++){
		for (j = 0; j < (Grado + 2); j++){
		  MatrizSuma[i][j] = ListaSumatoria[(j + i)];        
		}
	MatrizSuma[i][Grado + 1] = ListaSumatoria[Grado + Grado + i];
	}

    MatrizSuma[0][Grado + 1] = ListaSumatoria[0];
	MatrizSuma[0][0] = NumDatos;

	//Este for sirve para generar una matriz diagonal.
	for (i = 0; i < (Grado + 1); i++){
		VariableAuxiliar = MatrizSuma[i][i];

		for (j = 0; j < (Grado + 2); j++){
		  MatrizSuma[i][j] = (MatrizSuma[i][j] * (1/VariableAuxiliar));
		}

		/*Hay que convertir en 0 todos los valores que no sean la diagonal. Multiplicamos todos los valores de abajo y arriba
		 de la diagonal, luego sustituimos esta fila en la de abajo o arriba de la diagonal por la fila de la diagonal.
		 De esta forma vamos igualando todas las columnas, menos la diagonal, a 0*/
		for (int x = 0; x < (Grado + 1); x++){
		    VariableTemporal = x;
		    //Este if sirve para no igualar a 0 la diagonal.
			if (x == i){
			    VariableTemporal++;
			}
			VariableAuxiliar = (-MatrizSuma[VariableTemporal][i]);
			for(int w = 0; w < (Grado + 2); w++ ){
		    	EcuacionAuxiliar = (VariableAuxiliar * MatrizSuma[i][w]);
		    	MatrizSuma[VariableTemporal][w] += EcuacionAuxiliar;
		    }   
		}
	}

	//Se imprimen los resultados obtenidos.
	printf("\nSus resultados son: \n");
	for (i = 0; i < (Grado + 1); i++){
		printf("X%i = %f\n", (i+1), MatrizSuma[i][Grado + 1]);
	}

	// Se libera la memoria reservada.
	BorrarMatriz(MatrizSuma, (Grado + 2));
	BorrarMatriz(MatrizDatos, NumDatos);
	free(ListaSumatoria);

}