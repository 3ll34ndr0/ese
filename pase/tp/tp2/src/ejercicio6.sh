# Ejercicio 6: Escriba un script que defina una función que permita contar el número de líneas de
# un archivo que contienen una palabra específica. La función recibe como parámetros el archivo y
# la palabra y retorna como resultado el número de líneas. El script debe invocar a la función
# y mostrar el resultado.

cuantasVeces () {
    # Esta función cuenta la cantidad de apariciones en
    # todo el archivo (no es lo que se pide)
    local contador=0
while read line
do
    for word in $line
    do
        if [ $word = $2 ]
        then
            ((contador++))
        fi
    done
done <$1
echo $contador
}

cuantasLineas () {
    # Esta versión es la que si encuentra una línea
    # con la palabra buscada, incrementa el contador
    # y pasa a la siguiente línea.
    local contador
while read line
do
#    echo $line
    for word in $line
       do
              if [ $word = $2 ]
              then
                  ((contador++))
                  break # Sólo cuenta una vez
              fi
       done
done <$1
echo $contador
}


# Main
read -p "Ingrese un nombre de archivo: " archivo
read -p "Ingrese una palabra a buscar en el archivo $archivo: " palabra
echo "Se encontraron $(cuantasLineas $archivo $palabra) líneas que contienen esa palabra"
echo "La palabra $palabra aparece $(cuantasVeces $archivo $palabra) veces en ese archivo"

