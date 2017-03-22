
void delay(volatile unsigned int val)
{
    while(--val)
        ;
}

void *memset(void *s, int c, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        ((char *)s)[i] = c;
    }

    return s;
}

