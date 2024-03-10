# !/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <pattern>"
    exit 1
fi

pattern=$1
dir=$(pwd)

for file in $(find $dir -type f); do
    if grep -q $pattern $file; then
        echo $file
        grep -n $pattern $file
    fi
done
