 /*PROYECTO PRINCIPIOS DE PROGRAMACIÓN:
   LICENCIATURA EN CIENCIAS GENÓMICAS.
   Dante A. Torres Sepúlveda. */

#include <stdio.h>

int main()
{
/*DICCIONARIO DE VARIABLES

	-k,d: Funcionan como contadores para los -for- e -if-
	-respuesta: Permite volver a correr el programa si eso es lo que se quiere.
	-t: Delimita el número de casillas que va a utilizar el vector.
	-i: Marca el inicio del vector, o el inicio de la sección en la que se va a buscar.
	-x: Es la mitad del vector, o de la sección en la que se va a buscar.
	-n: El número del que vamos a calcular su posición dentro del vector.
	-vector: Almacena los números con los que se va a trabajar.
	-aux: Permite que no se pierda información al momento de ordenar los números en el vector.

 */
int n,x,i,t,respuesta,vector[10000],j,d=0,aux=0,k;
do{

//Se le informa al usuario qué hace el progra,a y se le piden los datos necesarios para funcionar.
printf("Hola, este programa va a decirte la  posición en la que está acomodao un número en un conjunto de números que introduzcas. Puede trabajar con numeros que estén entre -20,000 y 20,000\n");
printf("Ingresa tu número:\n");
scanf("%d",&n);
printf("¿Cuantos números vas a ingresar?\n");
scanf("%d",&t); 
printf("Ingresa una secuencia de números\n");
for (int k = 0; k < t ; k++){ //Este -for- va acomodando los numeros que ingreses en las casillas del vector y se asegura de que los números que ingreses no superen el rango establecido.
	scanf("%d", &vector[k]);
	if (vector[i]>20000||vector[i]<-20000){ 
		printf("Ingresaste un número incorrecto, por favor, sigue las especificaciones.\n");
		return 0;
	}
	if (vector[k]==n){ // Este -if- y el de abajo se aseguran de que el número que elegiste está dentro del vector.
		d++;
		}
} 

if (d==0)
{
	printf("Tristemente, tu numero no está en el conjunto. Intentalo de nuevo pero incluyendolo en la secuencia de números\n");
	return 0; // Si no metiste el número, el programa se cierra.
}

//Acomoda los números dentro del vector en orden ascendente. Si los números no están acomodados de esta forma, la búsqueda binaria pierde su sentido.
for (i = 0; i < t-1; i++){ 
	for ( j = 0; j < t-1; j++){
		if (vector[j]>vector[j+1]){
			aux=vector[j+1];
			vector[j+1]=vector[j];
			vector[j]=aux;
		}
	}
}

// Imprime el vector ordenado. Este paso sirve para que, una vez que el problema termine, puedas comprobar los resultados.
printf("Tu secuencia en orden:\n");
for (k = 0; k < t ; k++){ 
	printf("%d,",vector[k] );	
}

// Aquí se delimitan los valores del vector, inicio, mitad, final,
i=0;
x=(t-i+1)/2;


/* Este loop se encarga de hacer la búsqueda binaria. Si el número que elegiste es menor al vector en la mitad, cambia los parametros,
de forma que el final del vector se convierta en la mitad. Funciona casi igual si el numero es mayor, la diferencia es que en este caso
convierte la mitad en el inicio */
do{ 

	if(vector[x]>n){
		t=x;
		x=(t-i)/2;
	}

	if(vector[x]<n){
		i=x;
		x=(t+i)/2;

	}

} while(vector[x]!=n||(i>t)); // Cuando encuentra el número que estamos buscando se sale del loop.

// Imprime el resultado y repite el proceso si eso es lo que quieres.
printf("\nTu numero es %d y está en la posición %d\n", n, x+1); 
printf("Si quieres volver a correr el programa presiona 1, si quieres salir escribe 0.\n"); 
scanf("%d", &respuesta);

} while (respuesta==1);

return 0; 
}