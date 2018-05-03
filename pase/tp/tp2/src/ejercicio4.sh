#!/bin/bash

#Ejercicio 4: Escriba un script que defina la función menú. Dicha función imprime por pantalla los siguientes carteles: 1) Sumar; 2) Restar; 3) Salir y retorna como resultado la opción seleccionada por el usuario. El script debe invocar a la función y luego realizar la tarea indicada por el usuario.

function menu {
    echo "Elija una opción:"
    echo "1) Sumar"
    echo "2) Restar"
    echo "3) Salir"
    read opcion
    echo "Ud. eligió la opción $opcion"
    return $opcion
}

function echoParams {
while [ -n "$1" ]
do
    echo $1
    shift
done
}

# Llama al menú para obtener la opción del/a usuario/a
#menu.  Como la variable opcion es global no la asigno a nada
opcionUser= menu
case $opcion in
    1)read -p "Ingrese dos números: " sum1 sum2
    echo $((sum1 + sum2));;
    2)read -p "Ingrese dos números: " sum1 sum2
    echo $((sum1 - sum2));;
    *)echo "¡Adios!";;
esac

