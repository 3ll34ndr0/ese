#include "stdio.h"
#define TAM 5

int reduce(int (*functionPtr)(int,int), int * a){
int i, acum;
acum=a[0];
for(i=1;i<TAM;i++){
acum = (*functionPtr)(acum, a[i]);
}
return acum;
}

int suma(int a, int b){
return a+b;
}

int main(void){

/* Probamos el reduce sobre el arreglo y con la función suma*/
int i, nae[TAM] = {1,2,3,4,5};
printf("Arreglo original: ");
for(i=0;i<TAM;i++) printf("%i ", nae[i]);
printf("\nEl resultado de hacer reduce con suma a ese arreglo es: %i\n", reduce(&suma,nae));
return 0;
}
