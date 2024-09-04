// https://codeforces.com/contest/1872/problem/A
#include<iostream>
#include<cmath>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
    int t;cin>>t;
    while(t--)
    {
        int a,b,c; cin >> a >> b >> c;
        int tmp = abs(a-b)%2==0 ? abs(a-b)/2 : abs(a-b)/2+1;
        int ex =(int)(tmp%c==0 ? tmp/c : tmp/c+1);
        cout << ex << endl;
    }   
}