#!/bin/bash
# extracting command line options as parameters
if [ $# -eq 2 ]
then
  echo "Ud. ha ingresado dos números enteros."
  echo "Elija su opción:"
  echo "a: Suma"
  echo "b: Resta"
  echo "c: Producto"
  echo "d: Cociente"
  read operacion
  echo ""
    case "$operacion" in
        a) echo "$1 + $2 =$(($1+$2))" ;;
        b) echo "$1 - $2 =$(($1-$2))";;
        c) echo "$1 * $2 =$(($1*$2))" ;;
        d) echo "$1/$2 = $(($1/$2))";;
        *) echo "$operacion is not an option";;
    esac
else
        echo "¡Debe ingresar 2 enteros como parámetros!"
fi
