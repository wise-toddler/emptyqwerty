#include <iostream>
using namespace std;
void f(int i)
{
    static int c=0;
    while(c<i)
    {
        cout << c++ << endl;
    }
}
int main()
{
    f(5);
    cout << endl;
    f(10);
    return 0;
}