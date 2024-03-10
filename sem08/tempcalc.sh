#  !/bin/bash

# Uso: tempcalc.sh <archivo o directorio>

# Verificar que se haya ingresado un argumento
if [ $#  -ne 1 ]; then
    echo -e "\033[91;1mError:\033[0m No se ha ingresado ningún argumento."
    echo -e "\033[93;1mUso:\033[0m $0 <archivo o directorio>"
    exit 1
fi

ROUTE=$(realpath $1)

# Si el argumento es un directorio, combinar todos los archivos con temp y .txt en uno solo
if [ -d $ROUTE ]; then
    TEMPFILES=$(ls $ROUTE | grep "temp.*\.txt")
    TEMPFILES=$(echo $TEMPFILES | sed 's/ /|/g')
    cat $TEMPFILES > temp.txt
    ROUTE=$(realpath temp.txt)
fi

# Verificar que el argumento sea un archivo
if [ ! -f $ROUTE ]; then
    echo -e "\033[91;1mError:\033[0m El argumento ingresado no es un archivo .txt."
    echo -e "\033[93;1mUso:\033[0m $0 <archivo o directorio>"
    exit 1
fi

# Verificar que sea un archivo .txt
if [ ${ROUTE: -4} != ".txt" ]; then
    echo -e "\033[91;1mError:\033[0m El archivo ingresado no es un archivo .txt."
    echo -e "\033[93;1mUso:\033[0m $0 <archivo o directorio>"
    exit 1
fi

# Obtener los estadísticos
# Temperatura corporal promedio
AVGTEMP=$(awk '{sum+=$1} END {print sum/NR}' $ROUTE)
# Temperatura corporal máxima
MAXTEMP=$(awk 'BEGIN {max=0} {if ($1>max) max=$1} END {print max}' $ROUTE)
# Frecuencia cardíaca promedio de las mujeres y de los hombres
AVGFREQM=$(awk '{if ($2==2) {sum+=$3; count++}} END {print sum/count}' $ROUTE)
AVGFREQH=$(awk '{if ($2==1) {sum+=$3; count++}} END {print sum/count}' $ROUTE)
# Diferencia entre la frecuencia cardíaca promedio de las mujeres y de los hombres (En valor absoluto)
DIFF=$(awk -v avgfem=$AVGFREQM -v avghom=$AVGFREQH 'BEGIN {print (avgfem-avghom<0)? avghom-avgfem : avgfem-avghom}')
# Todas las líneas del archivo con temperatura mayor que 99.0
TEMP99=$(awk '{if ($1>99) print $0}' $ROUTE)

# Crear archivo results1_$(basename $ROUTE) que va a tener los datos ordenados por frecuencia cardíaca
cat $ROUTE | sort -k3 -n > results1_$(basename $ROUTE)

# Crear archivo results2_$(basename $ROUTE) que va a tener los datos con la temperatura expresada en grados Celsius
awk '{print ($1-32)*5/9, $2, $3}' $ROUTE > results2_$(basename $ROUTE)

# Mostrar los estadísticos
echo -e "Temperatura corporal promedio: \033[92;1m$AVGTEMP\033[0m"
echo -e "Mayor temperatura corporal: \033[92;1m$MAXTEMP\033[0m"
echo -e "Frecuencia cardíaca promedio de las mujeres: \033[92;1m$AVGFREQM\033[0m"
echo -e "Frecuencia cardíaca promedio de los hombres: \033[92;1m$AVGFREQH\033[0m"
echo -e "Diferencia entre la frecuencia cardíaca promedio de las mujeres y de los hombres: \033[92;1m$DIFF\033[0m"
echo -e "Todas las líneas del archivo con temperatura mayor que 99.0: \n\033[92;1m$TEMP99\033[0m"

# Eliminar el archivo temporal si fue creado
if [ -f temp.txt ]; then
    rm temp.txt
fi
