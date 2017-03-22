all:
	@echo this is target.
	@echo $(var1)

var = 123

ifeq ($(var), 123)
$(info 123)
var1 = kkkkk
else
$(info 456)
endif
