#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//
bool palindromo(char *cadena, int inicio, int fin)
{
    // Cadena con un solo caracter o vacia
    if (inicio >= fin)
        {
        return true;
        }

    // Si los caracteres no coinciden, no es un palindromo
    if (cadena[inicio] != cadena[fin])
        {
        return false;
        }

    // Llamada recursiva
    return palindromo(cadena, inicio + 1, fin - 1);
}

int main()
{
    char cadena[100];
    while (true){
    printf("Ingrese una cadena de caracteres: ");
    //%99s para que el maximo de caracteres leidos sean 99 y evitar desbordamiento
    scanf("%99s", cadena);
    if (strlen(cadena) > 10){
        printf("El dato ingresado es demasiado largo, intente nuevamente.\n");
    }
    else{
        break;
    }
    }
    
    

    // Verifica si la cadena es un palindromo
    if (palindromo(cadena, 0, strlen(cadena) - 1))
        {
        printf("La cadena %s es un palindromo.\n", cadena);
        }
    else
        {
        printf("La cadena %s no es un palindromo.\n", cadena);
        }

    return 0;
}
