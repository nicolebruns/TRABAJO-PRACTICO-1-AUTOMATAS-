#include <stdio.h>

const int estadoInicial = 0;
const int estadoFinal = 1;
const int estadoError = 2;
const char operaciones[3] = {'*', '+', '-'};

int columna(int caracter){
    if (caracter == '+' || caracter == '-' || caracter == '*') return 0;
    if (caracter >= '0' && caracter <= '9') return 1;
    return estadoError;
}

const int tt [3][3] = {
    //   +/-/*   0...9   error      
        {  2,      1,      2  },//0-
        {  0,      1,      2  },//1+
        {  2,      2,      2  },//2 (error)
};

int esPalabraLeng(const char* cadena){

    int i = 0;
	int estadoActual = estadoInicial;
	int caracter = cadena[0];

	while(caracter != '\0' && estadoActual != estadoError){
		estadoActual = tt[estadoActual][columna(caracter)];
		i++;
		caracter = cadena[i];
	}
    
	return (estadoActual == estadoFinal);
}

int verifica(char *s){
	unsigned i;
	for(i=0; s[i] != '\0'; i++){
        if(columna(s[i]) == estadoError) {return 0;}
	}
	return 1;
}

int esOperacion(char caracter){
    int resultado = 0;
    int i = 0;
    for(i; i < 3; i++){
        if(caracter == operaciones[i]) {resultado = 1;} 
    }
    return resultado;
}

void procesarOperacion(char operador, int numero, int *termino, int *resultado) {
    if (operador == '*') {
        *termino *= numero;
    } 
    else if (operador == '+') {
        *resultado += *termino;
        *termino = numero;
    } 
    else if (operador == '-') {
        *resultado += *termino;
        *termino = -numero;
    }
}

int evaluarExpresion(const char* cadena) {
    int resultadoTotal = 0;
    int terminoActual = 0;
    int numeroActual = 0;
    char operadorAnterior = '+'; // Arrancamos con '+' para el primer número

    int i = 0;
    char caracter = cadena[0];

    while(caracter != '\0') {
        
        if(!esOperacion(caracter)) {
            numeroActual = numeroActual * 10 + (caracter - '0');
        } 
        else if (esOperacion(caracter)) {

            procesarOperacion(operadorAnterior, numeroActual, &terminoActual, &resultadoTotal);

            operadorAnterior = caracter;
            numeroActual = 0;
        }
        
        i++;
        caracter = cadena[i];
    }

    procesarOperacion(operadorAnterior, numeroActual, &terminoActual, &resultadoTotal);

    return resultadoTotal + terminoActual;
}

int main() {
    // Podés cambiar esta cadena para probar distintos casos (ej: "5+", "A+2", "10-2*3")
    char expresion[] = "2+"; 
    
    printf("Analizando expresion: %s\n", expresion);
    printf("---------------------------------\n");

    // 1. Verificamos el alfabeto
    if(!verifica(expresion)) {
        printf("ERROR LEXICO: HAY CARACTERES QUE NO PERTENECEN AL ALFABETO.\n");
        return 0; // Corta la ejecución
    }

    // 2. Verificamos la sintaxis con el autómata
    if(!esPalabraLeng(expresion)) {
        printf("ERROR SINTACTICO: LA OPERACION ESTA MAL FORMADA.\n");
        return 0; // Corta la ejecución
    }

    // 3. Si pasó todos los filtros, evaluamos la matemática
    printf("ESTADO: EXPRESION VALIDA.\n");
    int resultado = evaluarExpresion(expresion);
    printf("RESULTADO FINAL: %d\n", resultado);

    return 0;
}