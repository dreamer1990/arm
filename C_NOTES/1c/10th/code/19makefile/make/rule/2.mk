
file1.o file2.o : source1.c source2.c
	gcc -c source1.c -o file1.o
	gcc -c source2.c -o file2.o
