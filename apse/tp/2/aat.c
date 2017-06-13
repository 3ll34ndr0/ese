#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define TAM 3

/* Aplicar a todo 

 Defina la función aplicarATodo. La función recibe como parámetro un arreglo de números enteros ae y una función f, la cual recibe como parametro un entero y retorna como resultado un entero. aplicarATodo aplica f a todos los elementos de ae y retorna como resultado el arreglo ae con todos los elementos modificados según la aplicación de f.

*/
int * aplicarATodo(int (*functionPtr)(int),int * a){
 int i;
 int *ae = (int*)malloc(TAM);
 // int *ae_ptr = (int*)malloc(TAM);
 for(i=0;i<TAM;i++){
  ae[i] = (*functionPtr)(a[i]);
 }
 return ae;
}


/* Esta versión trabaja sobre el arreglo original, es decir lo modifica */
void aplicarATodoD(int (*functionPtr)(int),int * a){
 int i,temp;
 for(i=0;i<TAM;i++){
  a[i]= (*functionPtr)(a[i]);
  }
}

int incrementa(int a){
 return a+1;
 }
 
int main(void){
int (*functionPtr)(int);
functionPtr = &incrementa;
int i, ae[TAM] = {0,1,2};
int *rae;
for(i=0;i<TAM;i++){
 printf("Hola %i \n", ae[i]);
 }

/* La versión que devuelve un arrego */
rae = aplicarATodo(functionPtr,ae);
for(i=0;i<TAM;i++){
 printf("Hola %i \n", rae[i]);
 }

/* La versión destructiva*/
aplicarATodoD(functionPtr,ae);
for(i=0;i<TAM;i++){
 printf("Hola %i \n", ae[i]);
 }


return 0;
}
