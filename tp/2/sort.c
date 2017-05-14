#include "stdio.h"
#include "sort.h"
void printArreglo(int *s){
int i;
for(i=0;i<TAM;i++) printf("%i ", s[i]);
printf("\n");
}

/* Ordena de mayor a menor */
void sort(int *s){
int i, j, temp;
for(i=0;i<TAM;i++){
      for(j=i;j<TAM;j++){
      if(s[i]<s[j]){temp=s[i];
                 s[i]=s[j];
                 s[j]=temp;
      }
/*      printArreglo(s); */
   }
}
}
void main(void){
/* int s[TAM]={9,8,7,6,5,4,3,2,1,0}; //Esto está atado a TAM :(*/
int s[TAM]={0,1,2,3,4,5,6,7,8,9}; //Esto está atado a TAM :(

printf("La lista de números sin ordenar es: \n");
printArreglo(s);

sort(s);
}
