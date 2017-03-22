
#代表注释
    #当依赖比目标"新"时执行命令.
    #基本规则:
    #target: prerequisite
    #<TAB>command
    
#目标:依赖
#	命令

#第一个目标是默认的目标
a:
	echo "bbbbbbb->  a"

all:
	echo "hello world"

#@表示执行该命令是不回显执行的命令
test:
	@echo "aaaaaaaaaaaaaaa--> test"
	@echo "bbbbbbbbbbbbbbb--> test"
	@echo "ccccccccccccccc--> test"


