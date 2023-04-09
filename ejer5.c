#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void agregarSeparadorMiles(char* num, int n, int i, int p) {
    if (i >= n) {
        return; // detener la recursión cuando se haya procesado todo el número
    }
    if (p == 3) {
        printf(".");
        p = 0;
    }
    printf("%c", num[i]);
    agregarSeparadorMiles(num, n, i+1, p+1);
}

int main() {
    char num[20];
    int i = 0;
    int p;
    while (1) {
        printf("Ingrese un numero (o \"salir\" para terminar): ");
        scanf("%s", num);
        if (strcmp(num, "salir") == 0) {
            break;
        }
        int n = strlen(num);
        if (n%3==0){
            p=0;
        }
        else if(n%3==1){
            p=2;
        }
        else p=1;
        agregarSeparadorMiles(num, n, i,p);
        printf("\n"); // agregar una nueva línea después de cada número procesado
    }
    return 0;
}
