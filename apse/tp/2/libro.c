#include "stdio.h"
#include "string.h"
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

/* Implemento el tipo de dato abstracto Libro */
typedef struct{
char nombre[128];
char autor[128];
char isbn[128];
char yearEd[128];
char editor[128];
} tipoLibro;

/* Crea una instancia de tipo libro, a partir del nombre nomás */
tipoLibro creaLibro(char *nombre){
tipoLibro libro;
strcpy(libro.nombre, nombre);
//libro.nombre = nombre;
return libro;
}

void setLibroYear(tipoLibro *libro, char *yearEd){
strcpy(libro->yearEd, yearEd);
}
char * getLibroYear(tipoLibro *libro){
return libro->yearEd;
}
void getLibroYear2(tipoLibro *libro, char *yearEd){
strcpy(yearEd, libro->yearEd);
}


/* Get an Set nombre del libro */
void setLibroName(tipoLibro *libro, char *nombre){
strcpy(libro->nombre, nombre);
}
char * getLibroName(tipoLibro *libro){
return libro->nombre;
}

/* Get an Set nombre del autor */
void setLibroAutor(tipoLibro *libro, char *autor){
strcpy(libro->autor, autor);
}
void getLibroAutor2(tipoLibro *libro, char *autor){
strcpy(autor, libro->autor);
}
char * getLibroAutor(tipoLibro *libro){
return libro->autor;
}
/* Get and set del ISBN */
void setLibroISBN(tipoLibro *libro, char *autor){
strcpy(libro->isbn, autor);
}
void getLibroISBN2(tipoLibro *libro, char *autor){
strcpy(autor, isbn->autor);
}
char * getLibroISBN(tipoLibro *libro){
return libro->isbn;
}

void main(void){
char tempo[128], tempo2[128];
strcpy(tempo,"EODELFYLPP!");
tipoLibro libro = creaLibro(tempo); //crea libro con el título
tipoLibro *lptr;
lptr = &libro;
strcpy(tempo,"2078");
setLibroYear(lptr,tempo);
printf("%s %s\n",libro.nombre, libro.yearEd);
strcpy(tempo,"El estado y la revolución!");
setLibroName(lptr,tempo);
printf("%s %s\n",libro.nombre, libro.yearEd);
//getLibroName(lptr,tempo);
getLibroYear(lptr,tempo2);
printf("%s %s\n",getLibroName(lptr), tempo2);
}


