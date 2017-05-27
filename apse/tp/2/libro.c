#include "stdio.h"
#include "string.h"
#include "libro.h"


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
 return libro->yearEd;
}

void getLibroYear2(Libro *libro, char *year){
 strcpy(year, libro->yearEd);
}


/* Get an Set nombre del libro */
void setLibroName(Libro *libro, char *nombre){
 strcpy(libro->nombre, nombre);
}
char * getLibroName(Libro *libro){
 return libro->nombre;
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
 //char *resultado = (char*)malloc(sizeof(char)*strlen(libro->autor));
 //strcpy(resultado,libro->autor);
 //return resultado;
 return libro->autor;
}

/* Get and set del ISBN */
void setLibroISBN(Libro *libro, char *isbn){
 strcpy(libro->isbn, isbn);
}
void getLibroISBN2(Libro *libro, char *isbn){
 strcpy(isbn, libro->isbn);
}
char * getLibroISBN(Libro *libro){
 return libro->isbn;
}
/* Get an Set nombre de la editorial*/
char * getLibroEditor(Libro *libro){
 return libro->editor;
}
void getLibroEditor2(Libro *libro, char *editor){
 strcpy(editor , libro->editor);
}
void setLibroEditor(Libro *libro, char *editor){
 strcpy(libro->editor, editor);
}


/* Lo que está arriba tienen que estar en el archivo que define el tipo de dato abstracto Libro */
/* Ingresar un libro */
void ingresaLibroUsr(Libro * lptr){
 char tempo[TAM];
/* Carga de un libro al arreglo */
 printf("Ingrese nombre libro: ");
 fgets_wrapper(tempo,TAM,stdin);
 setLibroName(lptr, tempo);
 printf("Ingrese autor/a/es/as del libro: ");
 fgets_wrapper(tempo,128,stdin);
 setLibroAutor(lptr,tempo);
 /* Año de la Edicion */
 printf("Ingrese el año de la edición: ");
 fgets_wrapper(tempo,128,stdin);
 setLibroYear(lptr,tempo);
 printf("Ingrese el nombre de la editorial: ");
 fgets_wrapper(tempo,128,stdin);
 setLibroEditor(lptr,tempo);
 printf("Ingrese el ISBN del libro: ");
 fgets_wrapper(tempo,128,stdin);
 setLibroISBN(lptr,tempo);
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

Libro * buscaISBN(Libro * lptr, char * isbn){
int i=0;
//if(isbn==getLibroISBN(al[i])){
//printf("Bingo!!\n");
//}
imprimeLibro(lptr);
//printf("%s \n", getLibroISBN(&al[i]));
//imprimeLibro(&al[i]);
}
/* Lo que está arriba son funciones que trabajan con los libros*/

/* Funciones auxiliares para el menu */
/*
void clear_screen()
{
char buf[1024];
char *str;
tgetent(buf, getenv("TERM"));
str = tgetstr("cl", NULL);
fputs(str, stdout);
} 
*/

/* Menu para la búsqueda y llenado de libros; */
void   cargarLibro(Libro * lptr, char * nombre, char * autor, char * year, char * editor, char * isbn){
/* Carga de un libro al arreglo */
setLibroName(lptr, nombre);
setLibroAutor(lptr, autor);
setLibroYear(lptr, year);
setLibroEditor(lptr, editor);
setLibroISBN(lptr, isbn);
}

Libro * llenarArregloLibros(void){
int opcion=1, cantidad=0;
char c;
char tempo[TAM];
Libro *lptr;
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
//ingresaLibroUsr(lptr); //crea libro con el título
imprimeLibro(lptr);
//al[cantidad] = *lptr;
//imprimeLibro(&al[cantidad]);
cantidad++;
printf("Ha ingresado el libro N° %d al arreglo.", cantidad);
break;
case 2:
/* Opción 2 */
//printf("Ingrese el ISBN del libro que desea buscar: ");
//fgets_wrapper(tempo,128,stdin);
//buscaISBN(lptr, tempo);
imprimeLibro(lptr);
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


