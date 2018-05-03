#!/bin/bash

# Ejercicio 7: Escriba un script que defina la función mostrarTodo. Esta función recibe como
# parámetro una extensión de archivo y muestra todos los archivos que se encuentran en la carpeta
# actual que tienen la extensión recibida como parámetro.

mostrarTodo () {

    for file in $PWD/* #Current directory
    do
        if [ -f $file ]
        then
            if [ $1 = ${file: -${#1}} ]
            then
                echo ${file##*/}
            fi
        fi
    done


}

