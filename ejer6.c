#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarEntPos(char num[]) {
    int i;
    if (num[0] == '-' || num[0] == '0'){
        printf("El valor ingresado debe ser mayor que cero.\n");
        return 0;
    }
    else{
        i=0;
    }
    for(; i<strlen(num); i++){
        if(!isdigit(num[i])){
            printf("El valor ingresado no es valido.\n");
            return 0;
        } 
    }
    if (atoi(num) > 100){
        printf("El valor ingresado es demasiado alto.\n");
        return 0;
    }
    return 1;
}

char* construirVistaFrontal(int nivel) {
    //Caso base
    if (nivel == 1) {
        return strdup("(-.-)");
    // 
    } else {
        char* vistaInterior = construirVistaFrontal(nivel - 1);
        char* vistaActual = malloc(strlen(vistaInterior) + 6);
        sprintf(vistaActual, "(-.%s.-)", vistaInterior);
        // Libera la memoria asignada al arreglo
        free(vistaInterior);
        return vistaActual;
    }
}

int main() {
    int nivel,n;
    char* vistaFrontal;
    char num[10];

    do{
        printf("Ingrese el nivel de la reunion: ");
        scanf("%s",&num);
        n=validarEntPos(num);
    }
    while (n==0);
    nivel=atoi(num);
    vistaFrontal = construirVistaFrontal(nivel);
    printf("Vista frontal de la delegacion: %s\n", vistaFrontal);
    free(vistaFrontal);

    return 0;
}