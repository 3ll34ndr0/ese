#include "stdio.h"
#include "string.h"
#include "libro.h"


void menu_loop(void){
 int opcion=1, cantidad=0;
 char c;
 char tempo[TAM];
 Libro al[TAM]; //Hasta 128 libros nomás
 while(opcion!=0){
  printf("          Las opciones son: \n");
  printf("Opción 1: Ingresar un nuevo libro al arreglo\n");
  printf("Opción 2: Búsqueda en la base de datos por ISBN\n");
  printf("Opción 0: Salir del programa\n");
  scanf ("%d",&opcion);
  while((c = getchar()) != '\n' && c != EOF);
  /* discard */;
  
  switch(opcion){
  case 1:
   /* Opcion 1 */
   creaLibro(&al[cantidad]);
   ingresaLibroUsr(&al[cantidad]); //crea libro con el título
   imprimeLibro(&al[cantidad]);
   cantidad++;
   printf("Ha ingresado el libro N° %d al arreglo.\n", cantidad);
   break;
  case 2:
   /* Opción 2 */
   printf("Ingrese el ISBN del libro que desea buscar: ");
   fgets_wrapper(tempo,128,stdin);
   buscaISBN(al, tempo, cantidad);
//   imprimeLibro(&al[cantidad-1]);
   break;
  case 0:
   /* Opción 3 */
   printf("¡Adios mundo!\n");
   break;
  default:
   printf("%d Opción incorrecta!\n", opcion);
  }
 }
}

void main(void){
/* Para cargar sin interacción con el usuario */
/* Libro libro;
 creaLibro(&libro);
 //cargarLibro(&libro, "Unombre", "unautor", "unanio", "uneditor", "unisbn"); */
 menu_loop();  

}

