

void _start(void)
{
    int (*func)(const char *, ...) = (void *)0x43e11a2c; 
    func("hello world\n");
}
