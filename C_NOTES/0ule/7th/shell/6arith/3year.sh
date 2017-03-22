#!/bin/bash

read -p "please input a year: " year

# year % 4 == 0 && year % 100 != 0 || year % 400 == 0

#$(()) 为真的时候 非零  $[]
#if [ $((year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) -ne 0 ]
if [ $[year%4] -eq 0  -a $[year%100] -ne 0 -o $[year%400] -eq 0 ]
then
    echo "$year is a leap year"
else
    echo "$year is not a leap year"
fi


exit 0
