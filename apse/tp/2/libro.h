#ifndef _LIBRO_H
#define _LIBRO_H
#define TAM 128
/* Implemento el tipo de dato abstracto Libro */
typedef struct{
char nombre[TAM];
char autor[TAM];
char yearEd[TAM];
char editor[TAM];
char isbn[TAM];
} Libro;

/* Crea una instancia de tipo libro, a partir del nombre nomás */
void creaLibro(Libro *);

void cargarLibro(Libro *,char * nombre, char * autor, char * year, char * editor, char * isbn);

void setLibroYear(Libro *, char *);
char * getLibroYear(Libro *);
void getLibroYear2(Libro *, char *);
void setLibroName(Libro *, char *);
char * getLibroName(Libro *);
void setLibroAutor(Libro *, char *);
void getLibroAutor2(Libro *, char *);
char * getLibroAutor(Libro *);
void setLibroISBN(Libro *, char *);
void getLibroISBN2(Libro *, char *);
char * getLibroISBN(Libro *);
char * getLibroEditor(Libro *);
void getLibroEditor2(Libro *, char *);
void setLibroEditor(Libro *, char *);
void ingresaLibroUsr(Libro *);
void imprimeLibro(Libro * );
void buscaISBN(Libro[TAM], char *isbn, int cantidad);

#endif
