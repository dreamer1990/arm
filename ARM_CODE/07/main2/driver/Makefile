
include $(TOPDIR)/config.mk 

OBJ = led.o
OBJ += buzzer.o
OBJ += key.o

OBJ_LIBS = libdriver.o

all: $(OBJ)
	$(AR) $(AR_FLAGS) $(OBJ_LIBS) $^

clean:
	rm -rf *.o


