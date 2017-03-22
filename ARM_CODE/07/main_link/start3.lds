
ENTRY(_start);
/*OUTPUT("start");*/
/*STARTUP("start.o");*/
OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm");
OUTPUT_ARCH(arm);

SECTIONS
{
    . = 0x50000000;     /*. 代表当前地址*/
    .text : {
        *(.text);
    }

    . = ALIGN(4);       /* 段开头保持4个字节对齐*/
    .rodata : {
        *(.rodata);
        *(.rodata.str1.4);
    }

    /*. = ALIGN(4);*/
    . = 0x50100000;
    .data : {
        *(.data);
    }

    . = ALIGN(4);
    .bss : {
        *(.bss); 
    }
};


