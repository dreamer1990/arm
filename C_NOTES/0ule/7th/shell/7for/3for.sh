#!/bin/bash

for n in `seq 1  5 100`
do
    echo "i = $n"
done

echo "==============="

for n in $(seq 10)
do
    echo "i = $n"
done



exit 0
