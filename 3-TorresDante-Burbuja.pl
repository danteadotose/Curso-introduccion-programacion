 #PROYECTO PRINCIPIOS DE PROGRAMACIÓN:
 # LICENCIATURA EN CIENCIAS GENÓMICAS.
 #Dante A. Torres Sepúlveda. */

#DICIONARIO DE VARIABLES:

#	-i,k: Funcionan como contadores dentro de los -for-
#	-aux: Funciona para que no se pierda información al momento de intercambiar posiciones dentro del vector.
#	-tamano: Delimita la cantidad de casillas del vector que van a ser utilizadas.
#	-vector: Almacena los números que vamos a ordenar
#	-respuesta: Permite repetir el procedimiento si eso es lo que se desea.

my @vector;
my $tamano;
my $i;
my $k;
my $aux;
my $respuesta;

do{
#Se le informa al usuario qué hace el progra,a y se le piden los datos necesarios para funcionar.
print"Hola, este programa está diseñado para ordenar de menor a mayor una serie de números que introduzcas. El rango en el que puede trabajar es de -20,000 a 20,000. Después de que ingreses cada número presiona enter.\n ¿Cuántos números quieres ingresar? Máximo 10,000\n";
$tamano=<STDIN>;
print"Ingresa un número y después presiona enter\n";

#Este -for- lee números proporcionados desde el teclado. También delimita el valor que puedan obtener estos.
for ($i = 0; $i < $tamano; $i++){ 
	$vector[$i]=<STDIN>;
	if ($vector[$i]>20000||$vector[$i]<-20000){
		print"Ingresaste un número incorrecto, por favor, sigue las especificaciones.\n";
		return 0;
		}
	}

#Este -for- recorre el vector. Si encuentra que en una casilla hay un número más alto que en la casilla siguiente, los cambia de lugar.
#Básicamente, ordena de menor a mayor
print"Tus números en orden acendente son:\n";

for ($k = 0; $k < $tamano-1; $k++){ 
	for ( $i= 0; $i < $tamano-1 ; $i++){
		if ($vector[$i]>$vector[$i+1]){
			$aux=$vector[$i+1];
			$vector[$i+1]=$vector[$i];
			$vector[$i]=$aux;
		}
	}
}

#Imprime el vector ordenado.
for ($k = 0; $k < $tamano; $k++){ 
	print"$vector[$k]";
}
#Repite el proceso si eso es lo que quieres.
print"Si quieres volver a correr el programa presiona 1, si quieres salir escribe 0.\n";
$respuesta=<STDIN>;
} while ($respuesta==1);

return 0;




