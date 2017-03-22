#!/bin/bash


#let i++  使i=i+1
i=100
echo "i = $i"

let i++
echo "i = $i"

echo "============="

#使 i=i+3
#let i=i+3  注意： let不能少
let i+=3
echo "i = $i"

echo "==========="
a=3
let a*=3
echo "a = $a"


exit 0
