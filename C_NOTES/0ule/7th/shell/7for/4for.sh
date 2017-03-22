#!/bin/bash

for i in `ls /etc/*.conf`
do
    echo "$i"
done

exit 0
