#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int validarEnt(char num[]) {
    int i;
    if (strlen(num) >= 5){
        printf("El dato ingresado es demasiado grande \n");
        return 0;
    }
    if (num[0] == '-') {
        i=1;
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
    return atoi(num);

   if (num == (int)num) {
      printf("%d es un numero entero.\n", (int)num);
   }
   else {
      printf("%.2f no es un numero entero.\n", num);
   }

   return 0;
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
    // Llamada recursiva
    if (n2 > 0) {
        return n1 + multiplicacion(n1, n2 - 1);

    } else{ 
        return -n1 + multiplicacion(n1, n2 + 1);
    }
}

int main()
{   
    char num1[99], num2[99];
    int num1V, num2V;
    do {
        printf("Ingrese el primer numero: ");
        scanf("%s",num1);
        num1V = validarEnt(num1);
    } while (num1V == 0);
    do {
        printf("Ingrese el segundo numero: ");
        scanf("%s",num2);
        num2V = validarEnt(num2);
    } while (num2V == 0);
    printf("El resultado de multiplicar %d con %d es: %d \n",num1V,num2V,multiplicacion(num1V,num2V));
    
    return 1;}
