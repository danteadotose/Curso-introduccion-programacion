 #PROYECTO PRINCIPIOS DE PROGRAMACIÓN:
  # LICENCIATURA EN CIENCIAS GENÓMICAS.
   #Dante A. Torres Sepúlveda. 


#DICCIONARIO DE VARIABLES

#	-vector: Almacena los 1s y 0s que van a representar el número binario.
#	-numero: EL número que convertiremos a binario.
#	-x,i: Funcionan como contadores para los for- e -if-.
#	-respuesta: Permite repetir el proceso si eso es lo que queremos. 


my $i;
my $x;
my $numero;
my $respuesta;
my @vector;


do{
# Explica para que funciona el programa y pide los datos necesarios para funcionar.
print"Hola, este programa convertirá un número que introduzcas en su equivalente en sistema binario.\n";
print"¿Qué numero quieres convertir? Maximo 32,767\n";
$numero=<STDIN>;

#El número decimal ya está en binario dentro de la computadora, lo que hace el programa es recorrerlo y hacer un -and-
#de tal forma que, si lo recorre y encuentra un 1,va a guardar en la casilla del vector un uno, de no encontrar el 1,
#esa casilla del vector se quedará en 0.*/
for ($x = 0; $x < 15; $x++){ 
	$i=$numero>>($x-1);
	if ($i&1 == 1){
		$vector[$x]=1;
	}
	else{
		$vector[$x]=0;
	}
	
}

#Imprime el vector en el que se guardó el numero en decimal.
for ($i = 15; $i > 0; $i--){
	print"$vector[$i]"; 
	}

#Repite el proceso si eso es lo que quieres.
print"\nSi quieres volver a correr el programa presiona 1, si quieres salir escribe 0.\n";
$respuesta=<STDIN>;
}while($respuesta==1);

return 0;

