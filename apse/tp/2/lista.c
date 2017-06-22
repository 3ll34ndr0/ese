#include "lista.h"
#include <stdlib.h>

/*
Una lista es una estructura de datos lineal en donde las in-
serciones y supresiones se pueden realizar en cualquier posición de la
lista. Teniendo en cuenta la definición antes mencionada implemente
:w
una lista de enteros con las siguientes operaciones:
• inicializar(l): inicializa la lista. El programador determina los
valores de inicialización.
• insertar(l,e,p): inserta en la lista l el elemento e en la posición p.
• suprimir(l,p): elimina de la lista l el elemento que se encuentra
en la posición p. Suprimir devuelve como resultado el elemento
eliminado.
• vacío(l): esta funcion devuelve verdadero si la lista l está vacía.
Falso en otro caso.
• lleno(l): esta función devuelve verdadero si la lista está llena.
Falso en otro caso.
• imprimir(l): imprime la lista.
• recuperarElemento(l,p): retorna como resultado el elemento de l
que se encuentra en la posición p.
*/


Lista * inicializar(){
   Lista * lista            = (Lista*)malloc(sizeof(Lista));
   lista->cabeza            = (Nodo*)malloc(sizeof(Nodo));
   lista->cabeza->siguiente = 0; //Null pointer
   setDatoNodo((lista->cabeza), 0);//valor de prueba
   lista->cola              = lista->cabeza; //Cola apunta a cabeza
   return lista;
}

/* Para acceder a los miembros de la lista */
int sizeOfLista(Lista * l){
//	if(!vacio(l));
	int i=1;
	while(lista-cabeza->siguiente!=0){i++;}
	return i;
}
int getHeadOfLista(Lista * l){
	return getDatoNodo(l->cabeza);
}
int getColaOfLista(Lista * l){
	return getDatoNodo(l->cola);
}
bool lleno(Lista * l){
	if(l->cabeza->siguiente==0);



/* Get and Set para el tipo de dato Nodo */
int getDatoNodo(Nodo * n){
	return n->dato;
}
void setDatoNodo(Nodo * n, int dato){
	n->dato = dato;
}

