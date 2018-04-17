#!/bin/bash

# Ejercicio 10: Haga un script que permita que los archivos pasados como parámetros,
# los cuales son todos ejecutables, se puedan ejecutar.

while [ "$1" ]
do
    echo "$1"
    $1 # Ejecuta el archivo
    shift # pasa al siguiente parámetro
done
