dirs := a b c
var1 := $(if 1, 123, 456)
files := $(foreach dir, $(dirs), $(wildcard $(dir)/*))

all:
	@echo $(files)
	@for var in `ls *`; do \
	  echo $$var; \
	done
	@echo var1 ========== $(var1)
