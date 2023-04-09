#include <stdio.h>
#include <ctype.h>

int divisible_por_7(int n) {
    if (n < 0) {
        return divisible_por_7(-n);  // si es negativo, se lo hace positivo
    }
    if (n == 0 || n == 7) {
        return 1;  // caso base: n es cero o siete
    }
    if (n < 10) {
        return 0;  // caso base: n es menor que diez y no es siete
    }
    int d = n % 10;  // se separa la última cifra
    n /= 10;         // se quita la última cifra
    int r = d * 2;   // se multiplica la última cifra por 2
    return divisible_por_7(n - r);  // se llama recursivamente con el nuevo valor de n
}

int main() {
    int n;
    char c;
    while (1) {
        printf("Ingrese un numero: ");
        if (scanf("%d", &n) == 1 && n < 9999) {  // se pudo leer un número correctamente
            if (divisible_por_7(n)) {
                printf("%d es divisible por 7\n", n);
            } else {
                printf("%d no es divisible por 7\n", n);
            }
            break;  // se sale del ciclo while
        } else {  // se ingresó una letra u otro caracter no numerico
            printf("Lo ingresado no es un numero valido.\n");
            while ((c = getchar()) != '\n' && c != EOF);  // se limpia el buffer de entrada
        }
    }
    return 0;
}
