#include <stdio.h>


int main() {
    char cadena[200];

    // estado inical y contadores
    int estado = 0; 
    int decimales = 0;
    int octales = 0;
    int hexadecimales = 0;
    int error = 0;

    printf("Ingrese la cadena: ");
    fgets(cadena, 200, stdin);

    // recorremos la cadena caracter por caracter 
    for (int i = 0; cadena[i] != '\0' && cadena[i] != '\n'; i++) {
        char c = cadena[i];

        // estdo inicial
        if (estado == 0) {
            if (c == '+' || c == '-') {
                estado = 1;
            }
            else if (c >= '1' && c <= '9') {
                estado = 2;
            }
            else if (c == '0') {
                estado = 3;
            }
            else {
                error = 1;
            }
        }

        // como leyo un signo sigue un digito
        else if (estado == 1) {
            if (c >= '0' && c <= '9') {
                estado = 2;
            }
            else {
                error = 1;
            }
        }

        // numero decimal
        else if (estado == 2) {
            if (c >= '0' && c <= '9') {
                estado = 2;
            }
            else if (c == '@') {
                decimales++;
                estado = 0;
            }
            else {
                error = 1;
            }
        }

        // leyo un cero inicial
        else if (estado == 3) {
            if (c >= '0' && c <= '7') {
                estado = 4;
            }
            else if (c == 'x' || c == 'X') {
                estado = 5;
            }
            else if (c == '@') {
                decimales++;
                estado = 0;
            }
            else {
                error = 1;
            }
        }

        // numero octal
        else if (estado == 4) {
            if (c >= '0' && c <= '7') {
                estado = 4;
            }
            else if (c == '@') {
                octales++;
                estado = 0;
            }
            else {
                error = 1;
            }
        }

        // leyo 0x o 0X, debe seguir un digito hexadecimal
        else if (estado == 5) {
            if ((c >= '0' && c <= '9') ||
                (c >= 'a' && c <= 'f') ||
                (c >= 'A' && c <= 'F')) {
                estado = 6;
            }
            else {
                error = 1;
            }
        }
       
        // Numero hexadecimal
        else if (estado == 6) {
            if ((c >= '0' && c <= '9') ||
                (c >= 'a' && c <= 'f') ||
                (c >= 'A' && c <= 'F')) {
                estado = 6;
            }
            else if (c == '@') {
                hexadecimales++;
                estado = 0;
            }
            else {
                error = 1;
            }
        }

        // Si una transicion no es valida, termina el recorrido
        if (error) {
            break;
        }
    }

    // cuenta el ultimo numero y verifica que termine en un estado final
    if (!error) {
        if (estado == 2) {
            decimales++;
        }
        else if (estado == 3) {
            decimales++;
        }
        else if (estado == 4) {
            octales++;
        }
        else if (estado == 6) {
            hexadecimales++;
        }
        else {
            error = 1;
        }
    }

    // resultados
    if (error) {
        printf("Error lexico.\n");
    }
    else {
        printf("Decimales: %d\n", decimales);
        printf("Octales: %d\n", octales);
        printf("Hexadecimales: %d\n", hexadecimales);
    }

    return 0;
}