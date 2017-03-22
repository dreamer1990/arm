
TARGET := test
OBJS := test.o a.o b.o



all:$(OBJS)
	gcc $(OBJS) -o $(TARGET)

test.o:test.c
	gcc -c test.c -o test.o

a.o:a.c
	gcc -c a.c -o a.o

b.o:b.c
	gcc -c b.c -o b.o

clean:
	rm -rf $(OBJS) $(TARGET)

	

