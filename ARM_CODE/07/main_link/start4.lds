
ENTRY(_start);
/*OUTPUT("start");*/
/*STARTUP("start.o");*/
OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm");
OUTPUT_ARCH(arm);

SECTIONS
{
    /*. = 0x02020000;   */  /*. 代表当前地址 可以使用与地址相关指令*/
    bl2 0x02020000 : AT(0x0) {  /*AT 指定文件的偏移量*/
        start.o
    }

    /*. = 0x43e00000;   */  /* 可以使用与地址相关指令 */
    u-boot 0x43e00000 : AT(0x2000) {
        main.o lib.o led.o buzzer.o key.o 
    }
};


