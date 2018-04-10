#
#Ejercicio 3: Escriba el script miOperacion. Este script utiliza dos opciones, la primera indica si la operación que se desea realizar es una suma o una multiplicación. La segunda opción utiliza un parámetro que indica el límite superior de una sumatoria o productoria dependiendo de la operación especificada por la primera opción. El script realiza la sumatoria o productoria desde 1 hasta el parámetro indicado en la segunda opción de los números que comienzan a partir de un parámetro del script miSumatoria. A continuación se muestra como el script se debería invocar:
#$ miOperacion -s -i 8 5. Este comando realiza de la sumatoria desde i=1 hasta 8 de 5+i.
#$ miOperacion -p -i 8 5. Este comando realiza de la productoria desde i=1 hasta 8 de 5*i.

if [ $# -eq 4 ]
then
   while [ -n "$1" ]
   do
      case "$1" in
            -s) #echo "Sumatoria:"
                operation="sumatoria";;
            -p) #echo "Productoria:"
                operation="productoria";;
            -i) limiteSuperior=$2
                escalar=$3
                echo "$operation entre 1 y $limiteSuperior ... "
                shift 3;;
            *) echo "$1 no es una opción válida";;
      esac
      shift
   done
else
################################################################
# Si hubo error de cantidad de parámetros:
   echo "Ejemplos de uso:"
   echo "El siguiente comando realiza la \
 sumatoria desde i=1 hasta 8 de 5+i:"
   echo "$0 -s -i 8 5 "
   echo ""
   echo "El siguiente comando realiza\
 la productoria desde i=1 hasta 8 de 5*i"
   echo "$0 -p -i 8 5"
   fi

###################################################
# Acá defino que hacer, si la sumatoria o productoria
# en base al valor de la variable $operation
if [ $operation="sumatoria" ]
then
    echo "Bla bla $operation"
    for i
else
    echo "Bla bla $operation"
fi

