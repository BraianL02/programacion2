#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int validarCadena(char cadena[100]){
    int i;
    int l = strlen(cadena);
    for (i=0;i<l-1;i++){
        // printf("cadena[%d]=>%c\n",i,cadena[i]);
        if (cadena[i] != 'H' && cadena[i] != 'h' && cadena[i] != 'L' && cadena[i] != 'l'){
            printf("La cadena contiene al menos un caracter invalido \n");
            return 0;
        } 
    }
    if (i>50){
        printf("La cadena es muy larga \n");
        return 0;
    }
    return 1;
}
void ondaDigitalRecursiva(char* cadena,int i,int n) {
    if (n-1>i){
        if (i>0 && cadena[i] != cadena[i-1]){
            printf("|"); 
        }
        if (cadena[i] == 'H' || cadena[i] == 'h'){
            printf("\xEE");
        }
        else printf("_");
        ondaDigitalRecursiva(cadena,i+1,n);
        }
    return;
}
int main() {
    char *cadena = NULL;
    size_t bufsize = 32;
    int i = 0, v;
    cadena = (char*) malloc(bufsize * sizeof(char));
    if (cadena == NULL) {
        printf("Error: no se pudo reservar memoria para cadena.\n");
        return 1;
    }
    memset(cadena, 0, bufsize); // inicializa cadena con valores nulos
    do {
        printf("Ingrese la cadena (H o L): ");
        getline(&cadena, &bufsize, stdin); 
        v = validarCadena(cadena);
    } while (v == 0);
    int n = strlen(cadena);
    ondaDigitalRecursiva(cadena, i, n);
    printf("\n");
    free(cadena);
    return 0;
}
