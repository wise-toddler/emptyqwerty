// https://atcoder.jp/contests/abc318/tasks/abc318_a
// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-1/Day-5.md

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