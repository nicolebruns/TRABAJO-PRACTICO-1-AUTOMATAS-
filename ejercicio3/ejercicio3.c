#include <stdio.h>
#define MAX 200

int validarExpresion(const char cadena[]) {
    int estado = 0;

    for (int i = 0; cadena[i] != '\0' && cadena[i] != '\n'; i++) {
        char c = cadena[i];

        if (estado == 0) {
            if (c >= '0' && c <= '9') {
                estado = 1;
            } else {
                return 0;
            }
        } else if (estado == 1) {
            if (c >= '0' && c <= '9') {
                estado = 1;
            } else if (c == '+' || c == '-' || c == '*') {
                estado = 2;
            } else {
                return 0;
            }
        } else if (estado == 2) {
            if (c >= '0' && c <= '9') {
                estado = 1;
            } else {
                return 0;
            }
        }
    }

    return estado == 1;
}

int leerNumero(const char cadena[], int *i) {
    int numero = 0;

    while (cadena[*i] >= '0' && cadena[*i] <= '9') {
        numero = numero * 10 + (cadena[*i] - '0');
        (*i)++;
    }

    return numero;
}


int evaluarExpresion(const char cadena[]) {
    int i = 0;
    int resultado = 0;
    int signo = 1;

    while (cadena[i] != '\0' && cadena[i] != '\n') {
        int termino = leerNumero(cadena, &i);

        while (cadena[i] == '*') {
            i++; // saltea '*'
            int siguiente = leerNumero(cadena, &i);
            termino *= siguiente;
        }

        resultado += signo * termino;

        if (cadena[i] == '+') {
            signo = 1;
            i++;
        } else if (cadena[i] == '-') {
            signo = -1;
            i++;
        }
    }

    return resultado;
}

int main(void) {
    char cadena[MAX];

    printf("Ingrese una operacion: ");
    fgets(cadena, MAX, stdin);

    if (!validarExpresion(cadena)) {
        printf("Error lexico: la cadena no pertenece al lenguaje.\n");
        return 0;
    }

    printf("Resultado: %d\n", evaluarExpresion(cadena));

    return 0;
}
