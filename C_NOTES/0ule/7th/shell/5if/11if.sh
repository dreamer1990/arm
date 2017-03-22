#/bin/bash


#2. 输入一个路径  ./test  ./txt  如果为目录就打包成test.tar.gz,并且删除目录
#                                如果为普通文件就打包成txt.tar.bz2
#    read -p "please input a path: "  path
#    -d 
#    -f
#    tar -cjvf 
#    tar -czvf 
#

read -p "please input a path:  " path

if [ -d $path ]
then
    tar -czvf $path.tar.gz $path && rm -rf $path &>/dev/null
elif [ -f $path ]
then
    tar -cjvf $path.tar.bz2 $path &>/dev/null
else
    echo "Nothing to do, $path"
fi

exit 0
