 #PROYECTO PRINCIPIOS DE PROGRAMACIÓN:
   #LICENCIATURA EN CIENCIAS GENÓMICAS.
   #Dante A. Torres Sepúlveda. 



#DICCIONARIO DE VARIABLES

#	-arreglo1: Guarda los numeros que el usuario introdusca a este arreglo en particular.
#	-arreglo2: Guarda los numeros que el usuario introdusca a este arreglo en particular.
#	-cantidad1 y cantidad2: Delimitan el número de números que va a introducir el usuario a cada arreglo
#	-numero: Guarda el número que introduce y lo acomoda dentro del arreglo.
#	-unionor, interseccion, difsim, difa1 y difa2: Representan la union,interseccion y diferencia simétrica y asimétrica entre los arreglos.
#	-vector: Guarda los numeros del arreglo para después convertirlos en números que el usuario puede leer fácilmente.
#	-respuesta: Repite el proceso si eso es lo que el usuario quiere.
#	-i,j: Sirven como contadores.


my $arreglo1=0;
my $arreglo2=0;
my $i;
my $cantidad1;
my $cantidad2;
my $numero;
my $unionor;
my $interseccion;
my $difsim;
my $j;
my @vector=0;
my $x;
my $difa1;
my $difa2;
my $respuesta;

do{
 
$arreglo1=0;
$arreglo2=0;
@vector=0;

#Explica para qué sirve el programa y pide los datos necesarios para funcionar.
print"Hola, este programa está diseñado para calcular la unión, intersección y diferencais simétricas y asimétricas de dos arreglos con distintos datos.\n";
print"¿Cuántos números quieres que tenga el arreglo # 1? Máximo 31\n";
$cantidad1=<STDIN>;

#Le pide al usuario un número y lo acomoda mediante corrimientos en forma de "1" dentro de un arreglo que puede contener hasta 32 elementos. Hace esto para el arreglo 1 y 2.
print"Ingresa tus números, estos pueden estar en el rango de 0 a 31.\n";
for ($i = 0; $i < $cantidad1; $i++){
	$numero=0;
	$numero=<STDIN>;
	$arreglo1=$arreglo1|(1<<($numero+1));
}
print"¿Cuántos números quieres que tenga el arreglo # 2? Máximo 31\n";
$cantidad2=<STDIN>;
print"Ingresa tus números, estos pueden estar en el rango de 0 a 31.\n";
for ($j = 0; $j < $cantidad2; $j++){
	$numero=0;
	$numero=<STDIN>;
	$arreglo2=$arreglo2|(1<<($numero+1));
}

#Pone en 0s todas las casillas del vector para evitar errores en los siguientes pasos.
for ($i = 0; $i < 31; $i++){
	$vector[$i]=0;
}

#Calcula la union,interseccion, dif. simétrica y asimétrica de cada arreglo utilizando operdadores buleanos sobre bits.
$unionor= $arreglo1|$arreglo2;
$interseccion= $arreglo1&$arreglo2;
$difsim=$arreglo1^$arreglo2;
$difa1=$arreglo1^($arreglo1&$arreglo2);
$difa2=$arreglo2^($arreglo2&$arreglo1);

#Pasa los 1s y 0s que surgieron de calcular la intersección de los arreglos a casillas en un vector. Impirme el resultado
for ($x = 0; $x < 31; $x++){ 
	$i=$interseccion>>$x;
	if ($i&1){
		$vector[$x]=1;
	}
}
print"\n\nLa intersección de sus arreglos son los números: \n";
for ($i = 31; $i > 0; $i--){
	if ($vector[$i]==1){
		printf",".($i-1);
	}
}

#Vuelve a poner en 0s todas las casillas del vector.
for ($i = 0; $i < 31; $i++){
	$vector[$i]=0;
}

#Pasa los 1s y 0s que surgieron de calcular la union de los arreglos a casillas en un vector. Imprime el resultado
for ($x = 0; $x < 31; $x++){ 
	$i=$unionor>>$x;
	if ($i&1){
		$vector[$x]=1;
	}
}
print"\nLa unión de sus arreglos son los números: \n";
for ($i = 31; $i > 0; $i--){
	if ($vector[$i]==1){
		print ",".($i-1);
	}
}

#Vuelve a poner en 0s todas las casillas del vector.
for ($i = 0; $i < 31; $i++){
	$vector[$i]=0;
}

#Pasa los 1s y 0s que surgieron de calcular la diferencia simétrica de los arreglos a casillas en un vector. Imprime el resultado
for ($x = 0; $x < 31; $x++){ 
	$i=$difsim>>$x;
	if ($i&1){
		$vector[$x]=1;
	}
}
print"\nLa diferencia simétrica de sus arreglos son los números: \n";
for ($i = 31; $i > 0; $i--){
	if ($vector[$i]==1){
		print",".($i-1);
	}
}

#Vuelve a poner en 0s todas las casillas del vector.
for ($i = 0; $i < 31; $i++){
	$vector[$i]=0;
}
#Pasa los 1s y 0s que surgieron de calcular la diferencia asimetrica del arreglo1 a casillas en un vector. Imprime el resultado
for ($x = 0; $x < 31; $x++){ 
	$i=$difa1>>$x;
	if ($i&1){
		$vector[$x]=1;
	}
}
print"\nLa diferencia asimetrica del arreglo 1 son los números: \n";
for ($i = 31; $i > 0; $i--){
	if ($vector[$i]==1){
		print",".($i-1);
	}
}
 
#Vuelve a poner en 0s todas las casillas del vector.
for ($i = 0; $i < 31; $i++){
	$vector[$i]=0;
}

#Pasa los 1s y 0s que surgieron de calcular la diferencia asimetrica del arreglo2 a casillas en un vector. Imprime el resultado
for ($x = 0; $x < 31; $x++){ 
	$i=$difa2>>$x;
	if ($i&1){
		$vector[$x]=1;
	}
}
print"\nLa diferencia asimetrica del arreglo 2 son los números: \n";
for ($i = 31; $i > 0; $i--){
	if ($vector[$i]==1){
		print ",".($i-1);
	}
}	
print"\nSi quieres volver a correr el programa presiona 1, si quieres salir escribe 0.\n"; #Repite el proceso si eso es lo que quieres.
$respuesta=<STDIN>;
} while ($respuesta==1);

return 0;

