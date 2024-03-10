# !/bin/bash
# utilice Sed para producir una versión del poema en donde todo lo 
# que hay entre dos apariciones de "flea" queda eliminado.

if [ $# -ne 1 ]; then
    echo "Usage: $0 <file>"
    exit 1
fi

file=$1

sed -n '/flea/,/flea/!p' $file
