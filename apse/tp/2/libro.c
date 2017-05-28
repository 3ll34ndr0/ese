#include "stdio.h"
#include "string.h"
#include "libro.h"
#include "stdlib.h"


/* Función para ingresar datos por el usuario */
char *fgets_wrapper(char *buffer, size_t buflen, FILE *fp)
{
    if (fgets(buffer, buflen, fp) != 0)
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n')
            buffer[len-1] = '\0';
        return buffer;
    }
    return 0;
}


/* Crea una instancia de tipo libro, a partir del nombre nomás */
void creaLibro(Libro *libro){
 setLibroName(libro,"");
 setLibroAutor(libro,"");
 setLibroEditor(libro,"");
 setLibroYear(libro,"");
 setLibroISBN(libro,"");
}

void setLibroYear(Libro *libro, char *year){
 strcpy(libro->yearEd, year);
}

char * getLibroYear(Libro *libro){
 char *resultado = (char*)malloc(sizeof(char)*strlen(libro->yearEd));
 strcpy(resultado,libro->yearEd);
 return resultado;
 //return libro->yearEd;
}

void getLibroYear2(Libro *libro, char *year){
 strcpy(year, libro->yearEd);
}


/* Get an Set nombre del libro */
void setLibroName(Libro *libro, char *nombre){
 strcpy(libro->nombre, nombre);
}
char * getLibroName(Libro *libro){
 //return libro->nombre;
 char *resultado = (char*)malloc(sizeof(char)*strlen(libro->nombre));
 strcpy(resultado,libro->nombre);
 return resultado;
}

void getLibroName2(Libro *libro, char *nombre){
 strcpy(nombre, libro->nombre);
}

/* Get an Set nombre del autor */
void setLibroAutor(Libro *libro, char *autor){
 strcpy(libro->autor, autor);
}

void getLibroAutor2(Libro *libro, char *autor){
 strcpy(autor, libro->autor);
}

char * getLibroAutor(Libro *libro){
 char *resultado = (char*)malloc(sizeof(char)*strlen(libro->autor));
 strcpy(resultado,libro->autor);
 return resultado;
 //return libro->autor;
}

/* Get and set del ISBN */
void setLibroISBN(Libro *libro, char *isbn){
 strcpy(libro->isbn, isbn);
}
void getLibroISBN2(Libro *libro, char *isbn){
 strcpy(isbn, libro->isbn);
}
char * getLibroISBN(Libro *libro){
 char *resultado = (char*)malloc(sizeof(char)*strlen(libro->isbn));
 strcpy(resultado,libro->isbn);
 return resultado;
 //return libro->isbn;
}
/* Get an Set nombre de la editorial*/
char * getLibroEditor(Libro *libro){
 //return libro->editor;
 char *resultado = (char*)malloc(sizeof(char)*strlen(libro->editor));
 strcpy(resultado,libro->editor);
 return resultado;

}
void getLibroEditor2(Libro *libro, char *editor){
 strcpy(editor , libro->editor);
}
void setLibroEditor(Libro *libro, char *editor){
 strcpy(libro->editor, editor);
}

/* Lo que está arriba tienen que estar en el archivo que define el tipo de dato abstracto Libro */

/* "Método" para que el usuario ingrese un libro interactivamente */
void ingresaLibroUsr(Libro * lptr){
 char usrIn[TAM];
/* Carga de un libro al arreglo */
 printf("Ingrese nombre libro: ");
 fgets_wrapper(usrIn,TAM,stdin);
 setLibroName(lptr, usrIn);
 printf("Ingrese autor/a/es/as del libro: ");
 fgets_wrapper(usrIn,128,stdin);
 setLibroAutor(lptr,usrIn);
 /* Año de la Edicion */
 printf("Ingrese el año de la edición: ");
 fgets_wrapper(usrIn,128,stdin);
 setLibroYear(lptr,usrIn);
 printf("Ingrese el nombre de la editorial: ");
 fgets_wrapper(usrIn,128,stdin);
 setLibroEditor(lptr,usrIn);
 printf("Ingrese el ISBN del libro: ");
 fgets_wrapper(usrIn,128,stdin);
 setLibroISBN(lptr,usrIn);
}


void imprimeLibro(Libro * lptr){
char nombre[TAM], autor[TAM], year[TAM], editor[TAM], isbn[TAM];
printf("\n");
 
printf("Nombre del libro:  %s\n", getLibroName(lptr));
printf("Autor/es/a/as:     %s\n", getLibroAutor(lptr));
printf("Año de la edición: %s\n", getLibroYear(lptr));
printf("Editorial:         %s\n", getLibroEditor(lptr));
printf("ISBN:              %s\n", getLibroISBN(lptr));

/*
getLibroName2(lptr,nombre);
getLibroAutor2(lptr, autor);
getLibroYear2(lptr, year);
getLibroEditor2(lptr, editor);
getLibroISBN2(lptr, isbn);
printf("Nombre del libro:  %s\n", nombre);
printf("Autor/es/a/as:     %s\n", autor);
printf("Año de la edición: %s\n", year);
printf("Editorial:         %s\n", editor);
printf("ISBN:              %s\n", isbn);
//printf("El tamaño del buffer del resultado es %d %d %d %d %d \n", strlen(getLibroName(lptr)), getLibroAutor(lptr),getLibroYear(lptr),getLibroEditor(lptr),getLibroISBN(lptr));
*/


}

void buscaISBN(Libro al[TAM], char * isbn, int cantidad){
 int i;
 for(i=0;i<cantidad;i++){
  if(strncmp(isbn, getLibroISBN(&al[i]), strlen(isbn)) == 0) {
   printf("Bingo! Libro encontrado!\n");
   imprimeLibro(&al[i]);
  } 
  //else {
  // prinf("No se encuentra el ISBN %s en nuestra base de datos.\n",isbn);
  //}
 }
}
/* Lo que está arriba son funciones que trabajan con los libros*/


/* Menu para la búsqueda y llenado de libros; */
void   cargarLibro(Libro * lptr, char * nombre, char * autor, char * year, char * editor, char * isbn){
/* Carga de un libro al arreglo */
setLibroName(lptr, nombre);
setLibroAutor(lptr, autor);
setLibroYear(lptr, year);
setLibroEditor(lptr, editor);
setLibroISBN(lptr, isbn);
}


