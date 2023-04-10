#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "recursividad.h"

int validarNat(char n[]){
    int i,c;
    if (strlen(n) > 5){
        printf("el valor es muy grande \n");
        return 0;
    }
    for (i=0;i<strlen(n);i++){
        if (!isdigit(n[i])){
            printf("el valor no es valido\n");
                return 0;
        }
    }
    c= atoi(n);
    if (c>40){
       printf("el valor es muy grande \n"); 
       return 0;
    }
    return 1;
}

int fibonacci(int k)
{
    //caso base
    if (k==0){
        return 0;
    }
    else if (k==1){
        return 1;
    }
    //llamada recursiva
    if (k>1){
        return fibonacci(k-1)+fibonacci(k-2);
    }
}


int main(){
    char k;
    int m;
    do{
        printf("ingrese la posicion de la secuencia:");
        scanf("%s",&k);
        
    }
    while(validarNat(&k)==0); 
    m= atoi(&k);   
    printf("El valor de la posicion %d de la secuencia de Fibonacci es %d \n",m,(int)fibonacci(m));
    return 1;
}