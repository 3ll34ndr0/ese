# Ejercicio 8: Escriba un script que defina la función apliqueATodos. Esta función recibe
# como parámetros un comando simple (comando con un parámetro y sin opciones) y una lista
# de archivos. La función aplica el comando a cada uno de los archivos recibidos como parámetros.

apliqueATodos () {
    comando=$1
    shift
    while [ -n "$1" ]
    do
        $comando $1
        shift
    done
}
