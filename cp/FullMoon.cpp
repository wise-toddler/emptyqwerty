#include <iostream>
using namespace std;

int main()
{
    int n,m,p;cin >> n >> m >> p; 
    if (n<m)
    {
        cout << 0;
        return 0;
    }
    cout << 1+(n-m)/p << endl;
}