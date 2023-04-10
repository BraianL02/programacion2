#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "recursividad.h"

int validarNatDiv(char num[],int divisor) {
    int i;
    if (num[0] == '-') {
        i=1;
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
    if (divisor){
        if (atoi(num) == 0){
            printf("El valor ingresado debe distinto que cero.\n");
            return 0;
        }}
    return 1;
}
// Funcion recursiva resuelve parte entera y retorna resto
int divide (int M, int N, int *rto){
    if (M < N) {
        *rto = M;
        return 0;  //cuando el dividendo es menor al divisor en la div.entera es 0
    }
    else {
        return (divide((M-N), N, rto) + 1);  //recursividad simple de pila con un parametro acumulador (rto)
    }
}
int positividad(int num){
    if (num < 0){
        return 0;
    }
    else{
        return 1;
    }
}
char *division(int M, int N){
    int i = 0;
    int resto = 0;
    int rta = 0;
    char num[10] = "";
    char *decimales;
    decimales = malloc(100);
    memset(decimales, 0, 100);  // limpia la cadena para que no retorne basura

    // Division para tomar la parte entera
    itoa(divide(M, N, &resto), num, 10);
    strcat(decimales, num);
    if (resto == 0) {
        return decimales;
    }
    strcat(decimales, ".");

    // procesa los 4 decimales si es necesario
    while ((resto != 0) && (i < 4)) {
        rta = divide((resto * 10), N, &resto);
        itoa(rta, num, 10);  // convierte rta a char* (num)
        strcat(decimales, num);  // concatena los decimales para retornarlos
        i++;
    }
    return decimales;
};

int main(){
    char dato1[100],dato2[100];
    int validacion1, M,signoN,signoM,signoR,validacion2, N,Mpos,Npos;
    do {
        printf("Ingrese el dividendo: ");
        scanf("%s", dato1);
        validacion1 = validarNatDiv(dato1,0);
    } while (validacion1 == 0);
    M = atoi(dato1);
    do {
        printf("Ingrese el divisor: ");
        scanf("%s", dato2);
        validacion2 = validarNatDiv(dato2,1);
    } while (validacion2 == 0);
    N = atoi(dato2);
    signoN=positividad(N);
    signoM=positividad(M);
    if (signoN == signoM) signoR=1;
    else signoR=0;
    if (signoN ==0) Npos=-N;
    else Npos=N;
    if (signoM == 0) Mpos=-M;
    else Mpos=M;
    printf("%d dividido %d da: ",M,N);
    if (signoR==0){
        printf("-");
    }
    printf("%s",division(Mpos,Npos));
    return 0;
}