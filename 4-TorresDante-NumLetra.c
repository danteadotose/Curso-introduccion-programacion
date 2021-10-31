 /*PROYECTO PRINCIPIOS DE PROGRAMACIÓN:
   LICENCIATURA EN CIENCIAS GENÓMICAS.
   Dante A. Torres Sepúlveda. */

 #include <stdio.h>
int main()
{
/*DICCIONARIO DE VARIABLES:

	-cifra: Es un vector, emcargado de almacenar cada uno de los digitos que conforman el número.
	-u,d,c,x,y,z: A cada una de estas letras se les va a asignar una posición del vector. Van desde unidad hasta centenas de millar.
	-r: Guarda un valor que va a determinar si queremos volver a correr el procedimiento.
*/

int cifra[6],u=0,d=0,c=0,x=0,y=0,z=0,r=0;
do
//Se le informa al usuario qué hace el progra,a y se le piden los datos necesarios para funcionar.
{ printf("Hola, a continuación tendrás que ingresar un número de máximo 6 cifras. Puedes utilizar 0s a la izquierda. Después de que ingreses cada número presiona enter. El programa te arrojará el número que introduciste pero escrito en letras\n");
printf("Centenas de millar\n");
scanf("%i",&cifra[0]);
printf("Decena de millar:\n");
scanf("%i",&cifra[1]);
printf("Unidad de millar:\n");
scanf("%i",&cifra[2]);
printf("Centena:\n");
scanf("%i",&cifra[3]);
printf("Decena:\n");
scanf("%i",&cifra[4]);
printf("Unidad:\n");
scanf("%i",&cifra[5]);
for (int i = 0; i < 6; ++i){
	if (cifra[i]<0||cifra[i]>9){
		printf("Ingresaste un número no válido. Por favor, vuelve a ingresar números positivos de únicamente un digito.\n");
		return 0;}	
}

//Aquí se le asigna a cada letra una posición del vector.
u=cifra[5]; //unidades
d=cifra[4]; //decenas
c=cifra[3]; //centenas
x=cifra[2]; //unidades de millar
y=cifra[1]; //decenas de millar
z=cifra[0]; //centenas de millar


// Asigna palabras dependiendo del valor que hayan tomado las letras en las posiciones determinadas del vector.
printf("Tú numero es: ");

if (z==1){
printf("ciento ");}
if (z==2){
printf("doscientos ");}
if (z==3){
printf("trescientos ");}
if (z==4){
printf("cuatrocientos ");}
if (z==5){
printf("quinientos ");}
if (z==6){
printf("seiscientos ");}
if (z==7){
printf("setecientos ");}
if (z==8){
printf("ochocientos ");}
if (z==9){
printf("noevecientos ");}

if (y==1&&(x!=0&&x!=1&&x!=2&&x!=3&&x!=4&&x!=5)){
	printf("diez y ");}
if (y==1&&x==1){
	printf("once mil ");}
if (y==1&&x==2){
	printf("doce mil ");}
if (y==1&&x==3){
	printf("trece mil ");}
if (y==1&&x==4){
	printf("catorce mil ");}
if (y==1&&x==5){
	printf("quince mil ");}
if (y==1&&x==0){ 
	printf("diez mil ");}
if (y==2&&x!=0){
	printf("veinti");}
if (y==2&&x==0){
	printf("veinte mil ");}
if (y==3&&x!=0){
	printf("treinta y ");}
if (y==3&&x==0){
	printf("treinta mil ");}
if (y==4&&x!=0){
	printf("cuarenta y ");}
if (y==4&&x==0){
	printf("cuarenta mil ");}
if (y==5&&x!=0){
	printf("cincuenta y ");}
if (y==5&&x==0){
	printf("cincuenta mil ");}
if (y==6&&x!=0){
	printf("sesenta y ");}
if (y==6&&x==0){
	printf("sesenta mil ");}
if (y==7&&x!=0){
printf("setenta y ");}
if (y==7&&x==0){
	printf("setenta mil ");}
if (y==8&&x!=0){
printf("ochenta y ");}
if (y==8&&x==0){
	printf("ochenta mil ");}
if (y==9&&x!=0){
printf("noventa y ");}
if (y==9&&x==0){
	printf("noventa mil ");}

if (x==1&&y!=1){
printf("un mil ");}
if (x==2&&y!=1){
printf("dos mil ");}
if (x==3&&y!=1){
printf("tres mil ");}
if (x==4&&y!=1){
printf("cuatro mil ");}
if (x==5&&y!=1){
printf("cinco mil ");}
if (x==6){
printf("seis mil ");}
if (x==7){
printf("siete mil ");}
if (x==8){
printf("ocho mil ");}
if (x==9){
printf("nueve mil ");}

if (c==1){
printf("ciento ");}
if (c==2){
printf("doscientos ");}
if (c==3){
printf("trescientos ");}
if (c==4){
printf("cuatrocientos ");}
if (c==5){
printf("quinientos ");}
if (c==6){
printf("seiscientos ");}
if (c==7){
printf("setecientos ");}
if (c==8){
printf("ochocientos ");}
if (c==9){
printf("noevecientos ");}

if (d==1&&(u!=0&&u!=1&&u!=2&&u!=3&&u!=4&&u!=5)){
	printf("diez y ");}
if (d==1&&u==1){
	printf("once\n");}
if (d==1&&u==2){
	printf("doce\n");}
if (d==1&&u==3){
	printf("trece\n");}
if (d==1&&u==4){
	printf("catorce\n");}
if (d==1&&u==5){
	printf("quince \n");}
if (d==1&&u==0){ 
	printf("diez \n");}
if (d==2&&u!=0){
	printf("veinti");}
if (d==2&&u==0){
	printf("veinte \n");}
if (d==3&&u!=0){
	printf("treinta y ");}
if (d==3&&u==0){
	printf("treinta \n");}
if (d==4&&u!=0){
	printf("cuarenta y ");}
if (d==4&&u==0){
	printf("cuarenta \n");}
if (d==5&&u!=0){
	printf("cincuenta y ");}
if (d==5&&u==0){
	printf("cincuenta \n");}
if (d==6&&u!=0){
	printf("sesenta y ");}
if (d==6&&u==0){
	printf("sesenta \n");}
if (d==7&&u!=0){
printf("setenta y ");}
if (d==7&&u==0){
	printf("setenta \n");}
if (d==8&&u!=0){
printf("ochenta y ");}
if (d==8&&u==0){
	printf("ochenta \n");}
if (d==9&&u!=0){
printf("noventa y ");}
if (d==9&&u==0){
	printf("noventa \n");}

if (u==1&&d!=1){
printf("uno \n");}
if (u==2&&d!=1){
printf("dos \n");}
if (u==3&&d!=1){
printf("tres \n");}
if (u==4&&d!=1){
printf("cuatro \n");}
if (u==5&&d!=1){
printf("cinco \n");}
if (u==6){
printf("seis \n");}
if (u==7){
printf("siete\n");}
if (u==8){
printf("ocho\n");}
if (u==9){
printf("nueve\n");}

//Imprime el numero.
printf("%d",z);
printf("%d",y);
printf("%d",x);
printf(",%d",c);
printf("%d",d);
printf("%d\n",u);

//Permite volver a ingresar un número y hacer otra vez el procedimiento.
printf("¿Quieres ingresar otro numero? Escribe 1 para sí y 0 para no\n");
scanf("%d",&r);
}while (r== 1);
return 0;
}
