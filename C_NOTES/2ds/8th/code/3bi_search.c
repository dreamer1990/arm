#include <stdio.h>

#define SIZE 11

//二分查找
int binary_search(int *a, int key, int n)
{
    int low;
    int high;
    int mid;

    low = 1;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if (*(a + mid) < key) 
        {
            low = mid + 1; 
        }
        else if (*(a + mid) > key)
        {
            high = mid - 1; 
        }
        else
        {
            return mid;
        }
    }
    
    return -1;
}

void array_show(int *a, int n)
{
    int i = 0;

    for (i = 1; i < n; i++)
    {
        printf("%2d  ", a[i]); 
    }
    putchar('\n');
}

int main(void)
{
    int key;
    
    //数组有序
    int a[11] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
    int b[12] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 100, 200};

    array_show(a, 11);

    printf("please input a number:   ");
    scanf("%d", &key);

    printf("find %d in index  %d\n", key, binary_search(a, key, 11));
    printf("find %d in index  %d\n", key, binary_search(b, key, 12));



    return 0;
}
