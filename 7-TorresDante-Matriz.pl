#PROYECTO PRINCIPIOS DE PROGRAMACIÓN:
 #  LICENCIATURA EN CIENCIAS GENÓMICAS.
  # Dante A. Torres Sepúlveda. 

# DICCIONARIO DE VARIABLES

#	-matriz: Almacena y muestra de forma gráfica las interacciones entre nodos.
#	-tamano: Delimita la cantidad de nodos con los que se va a trabajar.
#	-i,j,n: Funcionan como contadores para los -for- e -if-, "n" va a ser el que guarde los grados de los nodos.  


my $i;
my $j;
my @matriz;
my $tamano;
my $n=0;

#Explica que hace el programa, también rellena la matriz con 0s para evitar cualquier error en los pasos siguientes.
print"Hola, a continuación generarás una matriz que represente una red no dirigida y sus conexiónes. ¿Cuantos nodos hay en tu red?\n";
$tamano=<STDIN>;
for ($i = 0; $i < $tamano; $i++){ 
	for ( $j = 0; $j < $tamano; $j++)
	{
		$matriz[$i][$j]=0;
	}
}

chomp($i);
#Como no es una red dirigida, se puede llenar únicamente el triangulo superior derecho de la matriz para conocer todas las interacciones.
for ($i = 0; $i < $tamano; $i++){ 
	for ($j = $i+1; $j < $tamano; $j++){
	print"¿El nodo tiene " . ($i+1);
	print"conexión con el nodo " . ($j+1);
	print"?";
	$matriz[$i][$j]=<STDIN>;
		if ($matriz[$i][$j]==1){ # Llena los espacios faltantes con la información generada arriba.
				$matriz[$j][$i]=1;
		}
	}
}

#Imprime la matriz y espacios para que sea más fácil de analizar visualmente.
chomp ($i);
chomp ($j);
print"\nTu matriz es la siguiente:\n\n";
for ($i = 0; $i < $tamano; $i++){ 
	for ($j =0; $j < $tamano; $j++){
		print"  $matriz[$i][$j]";
	}
	print"\n"; 
}
print"\n";

# Suma las interacciones que presenta cada nodo e imprime su grado.
for ($i = 0; $i < $tamano; $i++){ 
	$n=0;
	for ($j = 0; $j < $tamano; $j++){
		if ($matriz[$i][$j]==1){
			$n++;
		}
	}
print"El nodo " . ($i+1);
print" tiene grado $n \n" ;
}

return 0;
