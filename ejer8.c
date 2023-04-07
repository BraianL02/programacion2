#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int validarEnt(char num[]) {
    int i;
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
    return 1;
}
int validarEntPos(char num[]) {
    int i;
    if (num[0] == '-') {
        printf("El valor ingresado debe ser positivo\n");
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
    return 1;
}
void print_subconj(int subconj[], int tam) {
    printf("[ ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", subconj[i]);
    }
    printf("]\n");
}

void subconj_recursivo(int s[], int tamanio, int obj_sum, int subconj[], int subconj_tamanio, int idx) {
    if (obj_sum == 0) {
        print_subconj(subconj, subconj_tamanio);
        return;
    }

    if (idx >= tamanio || obj_sum < 0) {
        return;
    }

    // caso en que el elemento en la posición actual no está incluido en el subconjunto
    subconj_recursivo(s, tamanio, obj_sum, subconj, subconj_tamanio, idx + 1);

    // caso en que el elemento en la posición actual está incluido en el subconjunto
    subconj[subconj_tamanio] = s[idx];
    subconj_recursivo(s, tamanio, obj_sum - s[idx], subconj, subconj_tamanio + 1, idx + 1);
}

void enctr_subconj(int s[], int tamanio, int obj_suma) {
    int subconj[tamanio];
    subconj_recursivo(s, tamanio, obj_suma, subconj, 0, 0);
}

int main() {
    int s[10];
    int i=0;
    while(i<10){
        char num1[20];
        int valor,n;
        do{
            printf("Ingrese un valor para el conjunto (o ingrese '0' para terminar): ");
            scanf("%s",&num1);
            n=validarEnt(num1);
        }while (n==0);
        valor=atoi(num1);

        if (valor == 0){ //Si se ingreso '0', termina de recibir numeros saliendo del while
            break;
        }
        s[i]=valor; // Almacenamos el valor ingresado en el arreglo
        i++;
    }
    int tamanio = sizeof(s) / sizeof(s[0]);
    int obj_sum,m;
    char num2[20];
    do{
        printf("Ingrese el valor objetivo de la suma: ");
        scanf("%s", &num2);
        m=validarEntPos(num2);
    }while (m==0);
    obj_sum=atoi(num2);
    enctr_subconj(s, tamanio, obj_sum);
    return 0;
}