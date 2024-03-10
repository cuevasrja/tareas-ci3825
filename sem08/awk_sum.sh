#  !/bin/bash

# Escriba un breve programa de Awk que sume los tamaños de los archivos en una carpeta.

if [ $# -ne 1 ]; then
    echo "Usage: $0 <folder>"
    exit 1
fi

folder=$(realpath $1)

awk 'BEGIN { sum = 0 }
     { sum += $5 }
     END { print sum }' <(ls -l $folder)
