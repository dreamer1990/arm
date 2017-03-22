#!/bin/awk
            
            BEGIN{              
                FS=":"
                count=0     #定义变量
            }

            {
                if($7 == "/sbin/nologin")
                {
                    count += 1
                    print $0  #输出当前行
                }
            }

            END{
                print "count="count 
            }
            
#awk -f 1.awk /etc/passwd        运行上面的脚本
