
object := source1.o source2.o

all: $(object)
	@echo target all ok.

$(object): %.o: %.c
	gcc $< -o $@ -c
