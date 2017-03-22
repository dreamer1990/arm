#include <stdio.h>


int main(void)
{
    // 1 2 3 4 
    // 5 7 8 10

    int i, j, k, m;

    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++) 
        {
            if (i == j) 
                continue;
            for (k = 1; k < 5; k++)
            {
                if (i == k || j == k) 
                    continue;
                    for (m = 1; m < 5; m++)
                    {
                        if (m == i || m == j || m == k) 
                            continue;
                            
                        printf("%d   %d   %d   %d\n", i, j, k, m);
                    
                    }
            }
        
        }
    }




    return 0;
}
