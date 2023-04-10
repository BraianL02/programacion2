#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "recursividad.h"
int validarEntPosP10(char num[]) {
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
            printf("El valor ingresado no es valido\n");
            return 0;
        } 
    }
    if ( i > 3){
        printf("El valor ingresado es demasiado grande\n");
        return 0;
    }

    return 1;
}
// Funcion recursiva que explota el número N con la bomba B y almacena los fragmentos en el arreglo fragmentos
// El numero de fragmentos generados se almacena en la variable num_fragmentos
void explosion(int N, int B, int *fragmentos, int *num_fragmentos) {
    // Caso base: N no es mayor que B, asi que no se puede explotar mas
    if (N <= B) {
        fragmentos[*num_fragmentos] = N;
        (*num_fragmentos)++;
        return;
    }

    // Explotar N en dos fragmentos N1 y N2
    int N1 = N / B;
    int N2 = N - N1;

    // Recursivamente explotar N1 y N2
    explosion(N1, B, fragmentos, num_fragmentos);
    explosion(N2, B, fragmentos, num_fragmentos);
}

int main() {
    char num1[10];
    int N,n1;
    do{
        printf("Ingrese el valor de N: ");
        scanf("%s",&num1);
        n1=validarEntPosP10(num1);
    }
    while(n1==0);
    N=atoi(num1);
    char num2[10];
    int B,n2;
    do{
        printf("Ingrese el valor de B: ");
        scanf("%s",&num2);
        n2=validarEntPosP10(num2);
        if (n2==1 && atoi(num2) == 1){printf("El valor de B debe ser mayor que 1\n");n2=0;};
    }
    while(n2==0);
    B=atoi(num2);
    if (N <= B){
        printf("La bomba no exploto porque el numero no es mas grande que el valor de la bomba. \n");
        return 1;
    }
    // Crear un arreglo para almacenar los fragmentos
    int *fragmentos = malloc(N * sizeof(int));
    int num_fragmentos = 0;
    
    // Llamo a la funcion explosion para generar los fragmentos
    explosion(N, B, fragmentos, &num_fragmentos);

    // Imprimo los fragmentos generados
    printf("Fragmentos de %d con la bomba %d:\n", N, B);
    printf("[ ");
    for (int i = 0; i < num_fragmentos; i++) {
        printf("%d ", fragmentos[i]);
    }
    printf("]");
    // Liberar la memoria asignada al arreglo
    free(fragmentos);
    return 1;
}
