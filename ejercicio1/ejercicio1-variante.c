#include <stdio.h>

const int tt [8][8] = {
//    +/-   0   1...7   8,9   x,X   a...f,A...F   @   error     
    {  6,   1,    5,     5,    7,        7,       7,    7 },//0-
    {  7,   1,    2,     7,    3,        7,       0,    7 },//1+ (decimal)
    {  7,   2,    2,     7,    7,        7,       0,    7 },//2+ (octal)
    {  7,   4,    4,     4,    7,        4,       7,    7 },//3
    {  7,   4,    4,     4,    7,        4,       0,    7 },//4+ (hexadecimal)
    {  7,   5,    5,     5,    7,        7,       0,    7 },//5+ (decimal)
    {  7,   5,    5,     5,    7,        7,       7,    7 },//6
    {  7,   7,    7,     7,    7,        7,       7,    7 }//7+ (error)
};

const int estadoInicial = 0;
const int estadosFinales[4] = {1,2,4,5};
int contadores[8] = {0};
int estadoError = 7;

int columna(int c){
    if (c == '+' || c == '-') return 0;
    if (c == '0') return 1;
    if (c >= '1' && c <= '7') return 2;
    if (c == '8' || c == '9') return 3;
    if (c == 'x' || c == 'X') return 4;
    if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) return 5;
    if (c == '@') return 6;
    
    return estadoError;
}

int terminoBien(int ultimoEstado){
    int resultado = 0;
    int i = 0;
    for(i; i < 4; i++){
        if(ultimoEstado == estadosFinales[i]) {resultado = 1;} 
    }
    return resultado;
}

int obtenerProximoEstado(int estadoActual, char caracter){
    return tt[estadoActual][columna(caracter)];
}

void identificarFin(char caracter, int estadoActual){
    int proximoEstado = obtenerProximoEstado(estadoActual, caracter);
    if((caracter == '@' || caracter == '\0') && terminoBien(estadoActual)) {contadores[estadoActual]++;}
}

int esPalabraLeng(const char* cadena){

    int i = 0;
	int estadoActual = estadoInicial;
	int caracter = cadena[0];

	while(caracter != '\0' && estadoActual != estadoError){
        identificarFin(caracter, estadoActual);
		estadoActual = tt[estadoActual][columna(caracter)];
		i++;
		caracter = cadena[i];
	}

    identificarFin(caracter, estadoActual);
    
	return terminoBien(estadoActual);
}

int verifica(char *s){
	unsigned i;
	for(i=0; s[i] != '\0'; i++){
        if(columna(s[i]) == 7) {return 0;}
	}
	return 1;
}

int main()
{

	char palabra[]="123@077@0xAF@+45";
	
	//si verificamos que los caracteres sean correctos
	if(!verifica(palabra))
	{
		printf("HAY CARACTERES QUE NO PERTENECEN AL ALFABETO");
		return 0;
	}
;
	if(esPalabraLeng(palabra))
	{
		printf("LA CADENA PERTENECE AL LENGUAJE.\n");
        printf("--------------------------------\n");
        // Sumamos los contadores 1 (cero aislado) y 5 (decimales)
        printf("Decimales: %d\n", contadores[1] + contadores[5]); 
        printf("Octales: %d\n", contadores[2]);
        printf("Hexadecimales: %d\n", contadores[4]);
		
	} else {printf("NO PERTENECE AL LENGUAJE");}
    return 0;
}