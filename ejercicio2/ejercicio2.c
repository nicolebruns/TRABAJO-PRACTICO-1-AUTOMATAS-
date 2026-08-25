#include <stdio.h>

int caracterAEntero(char c) {
    return c - '0';
}

int main() {
    char caracter;
    int numero;

    printf("Ingrese un caracter numerico: ");
    scanf(" %c", &caracter);

    while (caracter < '0' || caracter > '9') { // validacion de que es un numero y no otro tipo
        printf("Error: debe ingresar un caracter numerico.\n");
        printf("Ingrese un caracter numerico: ");
        scanf(" %c", &caracter);
    }

    numero = caracterAEntero(caracter);

    printf("El numero entero es: %d\n", numero);

    return 0;
}