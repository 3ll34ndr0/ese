#!/bin/bash

DIRECTORIO=$1
ARCHIVO_BUS=$2
shift 2
PALABRAS=$*
echo "Cantidad de parámetros: $#"
 if [ $# -ge 3 ]
      then
         ls $DIRECTORIO | grep $ARCHIVO_BUS | while read ARCHIVO
                                                 do
                                                    grep "$PALABRAS" ${DIRECTRIO}/${ARCHIVO}
                                                 done
      else
         echo "Número de argumentos insuficientes"
         echo "Use: $0 <directorio> <archivo_a_buscar> <palabras>"
 fi

 # Este script recibe 3 parámetros: Un directorio, un archivo y una o más palabras. Supuestamente
 # busca esas palabra en el archivo de ese directorio, si la encuentra nos dice en que líneas aparece.
 #
 # El problema es que nunca hace eso, ya que la condición de test nunca se cumple, debido
 # al shift 2. Por lo tanto para que funcione el test sería:
 # [ $# -ge 1 ]
 # Además hay un error de tipeo cuando usamos la variable DIRECTORIO en la línea 10. Corrijo los dos bugs
 # y el script queda así:

ejercicio9Corregido () {
DIRECTORIO=$1
ARCHIVO_BUS=$2
shift 2
PALABRAS=$* # Agrupa todos los parámetros restantes en una sola variable.
if [ $# -ge 1 ] # Luego del shift 2 deberían quedar al menos un parámetro (la/s palabra/s a buscar)
      then
         ls $DIRECTORIO | grep $ARCHIVO_BUS | while read ARCHIVO
                                                 do
                                                    echo "grep \"$PALABRAS\" ${DIRECTRIO}/${ARCHIVO}"
                                                    grep "$PALABRAS" ${DIRECTORIO}/${ARCHIVO}
                                                 done
      else
         echo "Número de argumentos insuficientes"
         echo "Use: $0 <directorio> <archivo_a_buscar> <palabras>"
 fi

}
