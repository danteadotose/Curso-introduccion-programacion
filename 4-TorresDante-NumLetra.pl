my @cifra;
my $u=0;
my $d=0;
my $c=0;
my $x=0;
my $y=0;
my $z=0;
my $r=0;

do
{ 
print"Hola, a continuación tendrás que ingresar un número de máximo 6 cifras. Puedes utilizar 0s a la izquierda. Después de que ingreses cada número presiona enter.\n";
print"Centenas de millar\n";
$cifra[0]=<STDIN>;
print"Decena de millar:\n";

$cifra[1]=<STDIN>;;
print"Unidad de millar:\n";
$cifra[2]=<STDIN>;
print"Centena:\n";
$cifra[3]=<STDIN>;
print"Decena:\n";
$cifra[4]=<STDIN>;
print"Unidad:\n";
$cifra[5]=<STDIN>;


for ($i = 0; $i < 6; $i++){
	if ($cifra[$i]<0||$cifra[$i]>9){
		print"Ingresaste un número no válido. Por favor, vuelve a ingresar números positivos de únicamente un digito.\n";
		return 0;}	
}

$u=$cifra[5];
$d=$cifra[4];
$c=$cifra[3];
$x=$cifra[2];
$y=$cifra[1];
$z=$cifra[0];

chomp ($z);
chomp ($x);
chomp ($y);
chomp ($c);
chomp ($u);
chomp ($d);

print"Tú numero es: ";

if ($z==1){
print"ciento ";}
if ($z==2){
print"doscientos ";}
if ($z==3){
print"trescientos ";}
if ($z==4){
print"cuatrocientos ";}
if ($z==5){
print"quinientos ";}
if ($z==6){
print"seiscientos ";}
if ($z==7){
print"setecientos ";}
if ($z==8){
print"ochocientos ";}
if ($z==9){
print"noevecientos ";}

if ($y==1&&($x!=0&&$x!=1&&$x!=2&&$x!=3&&$x!=4&&$x!=5)){
	print"diez y ";}
if ($y==1&&$x==1){
	print"once mil ";}
if ($y==1&&$x==2){
	print"doce mil ";}
if ($y==1&&$x==3){
	print"trece mil ";}
if ($y==1&&$x==4){
	print"catorce mil ";}
if ($y==1&&$x==5){
	print"quince mil ";}
if ($y==1&&$x==0){ 
	print"diez mil ";}
if ($y==2&&$x!=0){
	print"veinti";}
if ($y==2&&$x==0){
	print"veinte mil ";}
if ($y==3&&$x!=0){
	print"treinta y ";}
if ($y==3&&$x==0){
	print"treinta mil ";}
if ($y==4&&$x!=0){
	print"cuarenta y ";}
if ($y==4&&$x==0){
	print"cuarenta mil ";}
if ($y==5&&$x!=0){
	print"cincuenta y ";}
if ($y==5&&$x==0){
	print"cincuenta mil ";}
if ($y==6&&$x!=0){
	print"sesenta y ";}
if ($y==6&&$x==0){
	print"sesenta mil ";}
if ($y==7&&$x!=0){
	print"setenta y ";}
if ($y==7&&$x==0){
	print"setenta mil ";}
if ($y==8&&$x!=0){
	print"ochenta y ";}
if ($y==8&&$x==0){
	print"ochenta mil ";}
if ($y==9&&$x!=0){
	print"noventa y ";}
if ($y==9&&$x==0){
	print"noventa mil ";}

if ($x==1&&$y!=1){
print"un mil ";}
if ($x==2&&$y!=1){
print"dos mil ";}
if ($x==3&&$y!=1){
print"tres mil ";}
if ($x==4&&$y!=1){
print"cuatro mil ";}
if ($x==5&&$y!=1){
print"cinco mil ";}
if ($x==6){
print"seis mil ";}
if ($x==7){
print"siete mil ";}
if ($x==8){
print"ocho mil ";}
if ($x==9){
print"nueve mil ";}

if ($c==1){
print"ciento ";}
if ($c==2){
print"doscientos ";}
if ($c==3){
print"trescientos ";}
if ($c==4){
print"cuatrocientos ";}
if ($c==5){
print"quinientos ";}
if ($c==6){
print"seiscientos ";}
if ($c==7){
print"setecientos ";}
if ($c==8){
print"ochocientos ";}
if ($c==9){
print"noevecientos ";}

if ($d==1&&(u!=0&&$u!=1&&$u!=2&&$u!=3&&$u!=4&&$u!=5)){
	print"diez y ";}
if ($d==1&&$u==1){
	print"once\n";}
if ($d==1&&$u==2){
	print"doce\n";}
if ($d==1&&$u==3){
	print"trece\n";}
if ($d==1&&$u==4){
	print"catorce\n";}
if ($d==1&&$u==5){
	print"quince \n";}
if ($d==1&&$u==0){ 
	print"diez \n";}
if ($d==2&&$u!=0){
	print"veinti";}
if ($d==2&&$u==0){
	print"veinte \n";}
if ($d==3&&$u!=0){
	print"treinta y ";}
if ($d==3&&$u==0){
	print"treinta \n";}
if ($d==4&&$u!=0){
	print"cuarenta y ";}
if ($d==4&&$u==0){
	print"cuarenta \n";}
if ($d==5&&$u!=0){
	print"cincuenta y ";}
if ($d==5&&$u==0){
	print"cincuenta \n";}
if ($d==6&&$u!=0){
	print"sesenta y ";}
if ($d==6&&$u==0){
	print"sesenta \n";}
if ($d==7&&$u!=0){
	print"setenta y ";}
if ($d==7&&$u==0){
	print"setenta \n";}
if ($d==8&&$u!=0){
	print"ochenta y ";}
if ($d==8&&$u==0){
	print"ochenta \n";}
if ($d==9&&$u!=0){
	print"noventa y ";}
if ($d==9&&$u==0){
	print"noventa \n";}

if ($u==1&&$d!=1){
printf("uno \n");}
if ($u==2&&$d!=1){
printf("dos \n");}
if ($u==3&&$d!=1){
printf("tres \n");}
if ($u==4&&$d!=1){
printf("cuatro \n");}
if ($u==5&&$d!=1){
printf("cinco \n");}
if ($u==6){
printf("seis \n");}
if ($u==7){
printf("siete\n");}
if ($u==8){
printf("ocho\n");}
if ($u==9){
printf("nueve\n");}


print"$z$y$x,$c$d$u \n";


print"¿Quieres ingresar otro numero? Escribe 1 para sí y 0 para no\n";
$r=<STDIN>;
}while($r== 1);

return 0;

