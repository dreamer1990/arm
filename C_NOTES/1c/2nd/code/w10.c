#include <stdio.h>

/*
 *
 *14. 两个乒乓球队进行比赛，各出3人。甲对为A、B、C 3人，乙对为 X、Y、Z 3人。以抽签决定比赛名单。有人向队员打听比赛的名单，A说他不和X比赛，C说他不和X、Z比赛，请编程序找出3对赛手的名单。
 *
 */

int main(void)
{

    //  A  B  C
    int i, j, k;

    //A选手
    for (i = 'X'; i <= 'Z'; i++)
    {
        //B选手
        for (j = 'X'; j <= 'Z'; j++)   
        {
            if (i != j) 
            {
                //C选手
                for (k = 'X'; k <= 'Z'; k++) 
                {
                    if (i != k && j != k && i != 'X' && k != 'X' && k != 'Z') 
                    {
                        printf("=================\n");
                        printf("A -->  %c\n", i); 
                        printf("B -->  %c\n", j); 
                        printf("C -->  %c\n", k); 
                    }

                
                }
            }
        }
    
    }
    

    return 0;
}
