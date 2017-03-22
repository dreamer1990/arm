#/bin/bash

#1
#22
#333
#4444

i=1
j=1

#控制输出多少行
while true
do

    #控制循环结束的条件
    if [ $i -eq 10 ]
    then
        break
    fi

    if [ $i -eq 3 ]
    then
        let i++
        continue
    fi
    #控制一行的输出
    j=1
    while :
    do
        #循环结束的条件
        if [ $j -gt $i ]
        then
            break
        fi
         echo -n "$i"
        let j++
    done
    echo
    let i++
done

exit 0

