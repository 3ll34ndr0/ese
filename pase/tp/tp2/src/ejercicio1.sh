#!/bin/bash
paso=$1
files=$2

echo "Copiando ... "
for i in `cat $files`
do
    echo " $i"
    cp $i $paso
done
echo "en el directorio $paso"

