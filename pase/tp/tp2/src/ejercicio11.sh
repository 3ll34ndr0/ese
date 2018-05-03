#!/bin/bash

# Ejercicio 11: Escriba un script que reciba como parámetro un paso donde se
# encuentran archivos .c (sin dependencias entre si) los compile  y luego cree
# dos carpetas una Ejecutables y la otra Fuentes y copie los archivos fuentes
# en la carpeta Fuentes y los ejecutables en la carpeta Ejecutables.

# Zona para configurar
# Directorio donde se guardarán los archivos fuentes:
FUENTES="Fuentes"
# Directorio donde se guardarán los ejecutables:
EJECUTABLES="Ejecutables"
# Compilador a usar:
GCC=gcc
#

source ejercicio7.sh # Importa la función mostrarTodo

originalDir=`pwd` # Recuerda el directoria desde donde fue ejecutado, para volver.
directorio=$1
cd $directorio

#
if [ -d $FUENTES ] && [ -d $EJECUTABLES ]
then
    echo "Los directorios $FUENTES y $EJECUTABLES ya existen"
else
    mkdir $FUENTES ; mkdir $EJECUTABLES
fi
#

# Compilo
mostrarTodo .c $directorio | while read SOURCE
                    do
                        base=${SOURCE%%.*} # Le borra la extensión al archivo
                        echo "$GCC $SOURCE -o $base"
                        $GCC $SOURCE -o $base # Para hacer el ejecutable sin extensión
                        echo "cp $SOURCE $FUENTES ; cp $base $EJECUTABLES "
                        cp $SOURCE $FUENTES ; cp $base $EJECUTABLES
                    done

