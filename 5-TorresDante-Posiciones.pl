use POSIX;

my $n=0;
my $x=0;
my $i=0;
my $t=0;
my $respuesta=0;
my @vector=0;
my $j=0;
my $d=0;
my $aux=0;
my $k=0;

print"Hola, este programa va a decirte la  posición en la que está acomodao un número en un conjunto de números que introduzcas. Puede trabajar con numeros que estén entre -20,000 y 20,000\n";
do{
print"Ingresa tu número:\n";
$n=<STDIN>;
print"¿Cuantos números vas a ingresar?\n";
$t=<STDIN>;
print"Ingresa una secuencia de números\n";

for ($k = 0; $k < $t ; $k++){ 
	$vector[$k]=<STDIN>;
	if ($vector[$i]>20000||$vector[$i]<-20000){ 
		print"Ingresaste un número incorrecto, por favor, sigue las especificaciones.\n";
		return 0;
		} if ($vector[$k]==$n){ 
		$d++;
	}
}
if ($d==0)
{
	print"Tristemente, tu numero no está en el conjunto. Intentalo de nuevo pero incluyendolo en la secuencia de números\n";
	return 0; 
}

for ($i = 0; $i < $t-1; $i++){ 
	for ( $j = 0; $j < $t-1; $j++){
		if ($vector[$j]>$vector[$j+1]){
			$aux=$vector[$j+1];
			$vector[$j+1]=$vector[$j];
			$vector[$j]=$aux;
		}
	}
}

print"Tu secuencia en orden:\n";
for ($k = 0; $k < $t ; $k++){ 
	chomp ($vector[$k]);
	print",$vector[$k]";	
}

$i=0;
$x=0;
$x=floor(($t-$i+1)/2);

do{ 

	if($vector[$x]>$n){
		$t=$x;
		$x=floor(($t-$i)/2);
	}

	if($vector[$x]<$n){
		$i=$x;
		$x=floor(($t+$i)/2);

	}

} while($vector[$x]!=$n);

chomp ($n);
print"\nTu numero es $n y está en la posición " . ($x+1) ;
print"\nSi quieres volver a correr el programa presiona 1, si quieres salir escribe 0.\n";
$respuesta=<STDIN>;

} while ($respuesta==1);

return 0; 

