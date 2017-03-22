#include <iostream>
using namespace std;


int main(void)
{
    int i, j;

    for (i = 1; i < 10; i++)
    {
        for (j = 1; j <= i; j++) 
        {
            cout << j << "*" << i << "=" << i * j << " "; 
        }
        //换行
        cout << endl;
    }



    return 0;
}
