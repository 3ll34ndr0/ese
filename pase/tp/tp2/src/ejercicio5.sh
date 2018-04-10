#!/bin/bash
# Ejercicio 5: Escriba un script que defina la función mayor. La función recibe como parámetros
# dos números y retorna como resultado el mayor. El script pide al usuario dos números e invoca
# a la función. Luego de realizada dicha tarea imprime la leyenda “El número mayor es:” y seguidamente
# el valor retornado por la función.


mayor () {
if [ $1 \> $2 ]
then
    echo $1
else
    echo $2
fi
}

read -p "Ingrese dos números: " var1 var2
echo "El mayor de los dos es: $(mayor $var1 $var2)"
