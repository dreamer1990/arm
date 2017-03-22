#include <stdio.h>

int main(void)
{
    int a[2][3][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, 
                 {{11, 22, 33, 44}, {55, 66, 77, 88}, {10, 11, 12, 13}}};
    int i, j, k;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++) 
        {
            for (k = 0; k < 4; k++) 
            {
                printf("%2d  ", a[i][j][k]); 
            }
            printf("\n");
        }

        printf("===================\n");
    }

    return 0;
}
