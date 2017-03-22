
#!/bin/sh

PICTURE=../Picture
HEADER=../bmp.h

echo > $HEADER

echo "#ifndef _BMP_H" >> $HEADER
echo "#define _BMP_H" >> $HEADER

echo >> $HEADER
echo >> $HEADER
echo >> $HEADER
echo >> $HEADER

i=0
for tmp in `ls	$PICTURE`
do
	let	"i++"
done

echo "int picturecount = $i ;" >> $HEADER

echo "unsigned int BMP[] = { " >> $HEADER

for	tmp in `ls	$PICTURE`
do
	echo "$tmp"
	./mkheader  $PICTURE/$tmp  $HEADER
done

echo "};" >> $HEADER

echo >> $HEADER
echo >> $HEADER
echo >> $HEADER

echo "#endif //_BMP_H"  >> $HEADER



