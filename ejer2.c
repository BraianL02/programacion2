// Dados dos números enteros m y n, construir una función recursiva que devuelva el
// producto de ambos, calculando el mismo como sumas sucesivas. Esto es:
// m*n=m+m+...+m, n veces.
// Ejemplos:
// producto(5, 3) => 15
// producto (10, 4) => 40 

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int validarEnt(char num[]) {
    // int i;
    // for(i=0; i<strlen(num); i++){
    //     if(!isdigit(num[i])){
    //         printf("El valor ingresado no es numerico\n");
    //         return 0;
    //     } 
    // }
    // return 1;

//    if (num == (int)num) {
//       printf("%d es un numero entero.\n", (int)num);
//    }
//    else {
//       printf("%.2f no es un numero entero.\n", num);
//    }

//    return 0;
}


int multiplicacion(int n1, int n2)
{   
    int aux;
    //Para evitar hacer iteraciones de más innecesariamente
    if (n2 > n1){ 
        aux = n2;
        n2=n1;
        n1=aux;
    }
    // Caso base
    if (n2 == 0) {
        return 0;
    }

    if (n2 > 0) {
        return n1 + multiplicacion(n1, n2 - 1);

    } else{ 
        return -n1 + multiplicacion(n1, n2 + 1);
    }
}

int main()
{   
    char num1[5], num2[5];
    int i;
    int n,m;
    int num1V, num2V;
    do{
        printf("Ingrese el primer numero: ");
        n=scanf("%d",num1);
    }
    while (n==0);
    num1V = atoi(num1);
    do{
        printf("Ingrese el multiplicando: ");
        m=scanf("%d",num2);
    }
    while (m==0);

    num2V = atoi(num2);
    printf("El resultado de multiplicar %d con %d es: %d \n",num1V,num2V,multiplicacion(num1V,num2V));
    
    return 1;}