
object := file_1.c file_2.c file_3.c

var := $(patsubst %.c,%.o,$(object))
LDFLAGS_BUILD_ID := $(patsubst -Wl$(comma)%,%,\
	-Wl$(comma)--build-id)

all:
	@echo $(LDFLAGS_BUILD_ID)
	@echo $(var)
