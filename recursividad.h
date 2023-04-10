#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Ejercicio 1
#ifndef ejer1
#define ejer1 
bool palindromo(char *cadena, int inicio, int fin);
#endif

// Ejercicio 2
#ifndef ejer2
#define ejer2
int validarEnt(char num[]);
int multiplicacion(int n1, int n2);
#endif

// Ejercicio 3
#ifndef ejer3
#define ejer3
int validarNat(char n[]);
int fibonacci(int k);
#endif

// Ejercicio 4
#ifndef ejer4
#define ejer4
int validarNatDiv(char num[],int divisor);
int divide (int M, int N, int *rto);
int positividad(int num);
char *division(int M, int N);
#endif

// Ejercicio 5
#ifndef ejer5
#define ejer5
void agregarSeparadorMiles(char* num, int n, int i, int p);
#endif

// Ejercicio 6
#ifndef ejer6
#define ejer6
int validarEntPos(char num[]);
char* construirVistaFrontal(int nivel);
#endif

// Ejercicio 7
#ifndef ejer7
#define ejer7
int validarCadena(char cadena[100]);
void ondaDigitalRecursiva(char* cadena,int i,int n);
#endif

// Ejercicio 8
#ifndef ejer8
#define ejer8
int validarEntP8(char num[]);
int validarEntPosP8(char num[]);
void print_subconj(int subconj[], int tam);
void subconj_recursivo(int s[], int tamanio, int obj_sum, int subconj[], int subconj_tamanio, int idx);
void enctr_subconj(int s[], int tamanio, int obj_suma);
#endif

// Ejercicio 9
#ifndef ejer9
#define ejer9
int divisible_por_7(int n);
#endif

// Ejercicio 10
#ifndef ejer10
#define ejer10
int validarEntPosP10(char num[]);
void explosion(int N, int B, int *fragmentos, int *num_fragmentos);
#endif