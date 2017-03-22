define two-lines
$(info $(1))
$(info $(2))
endef

var:=$(call two-lines,666,777)

all:
	@echo kkkkkkkkkk
