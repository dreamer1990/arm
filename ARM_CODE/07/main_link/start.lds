
ENTRY(_start);
/*STARTUP("start.o");*/
OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm");
OUTPUT_ARCH(arm);

SECTIONS                /* 各个段的布局1)内存布局2)文件中布局 */
{
    . = 0x50000000;     /*. 代表当前地址*/
    .text : {
        start.o(.text);
        main.o(.text);
        *(.text);       /*链接所有其他的输入文件.text */
    }   

    /*
    . = 0x50100000;
    .cmd : {
        lib.o(.text);
    }
    */

    . = ALIGN(4);       /* 段开头保持4个字节对齐*/
    .rodata : {
        *(.rodata);
    }

    . = ALIGN(4);
    .data : {
        *(.data);
    }

    . = ALIGN(4);
    __bss_start = .;    /* 当前位置设置标签 __bss_start: */
    .bss : {
        *(.bss); 
    }
    __bss_end = .;      /* 当前位置设置标签 __bss_end: */
};


