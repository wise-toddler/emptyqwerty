#include <stdio.h>
// using namespace std;
void f(int i)
{
    static int c=0;
    while(c<i)
    {
        printf("%d\n", c);
        c++;
    }
}
int main()
{
    f(5);
    // cout << endl;
    printf("\n");
    f(10);
    return 0;
}