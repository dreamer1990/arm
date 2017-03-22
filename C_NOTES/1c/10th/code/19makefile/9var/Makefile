
#隐式规则
TARGET := test
OBJS := test.o a.o b.o
CC := gcc
CFLAGS := -g
INC := .
LIB := .

src :=$(OBJS:.o=.c)

     #内置变量:
     #--------------------------------
     #$@ 规则目标
     #$< 规则依赖中第一个预备文件
     #$^ 规则依赖中所有预备文件的完整清单
     
     #$(@D) 规则目标文件的所在目录
     #$(@F) 规则目标文件的文件名
     
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -I$(INC) -L$(LIB) $^ -o  $@
	@#echo $(@D)
	@#echo $(@F)
	@echo $(src)


%.o:%.c
	@$(CC) -c  $< -o $@

.PHOYN:clean
clean:
	@#以下两种方式等价
	@#rm -rf $(OBJS) $(TARGET)
	@#rm -rf *.o test
	$(RM) -rf $(OBJS) $(TARGET)

	

