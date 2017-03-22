#include <iostream>

using namespace std;

int main(void)
{
    pair<int, string> p(1, "hello uplooking");
    pair<int, string> p1(p);

    cout << "key: " << p.first << " ====> value: " << p.second << endl;
    cout << "key: " << p1.first << " =====> value: " << p1.second << endl;

    return 0;
}
