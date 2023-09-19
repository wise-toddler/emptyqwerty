// https://atcoder.jp/contests/abc320/tasks/abc320_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
int pow(int a,int b)
{
    int ans=1;
    while(b!=0)
    {
        if( b & 1 )//b%2==1
        {
            ans*=a;
        }
        b>>=1;
        a*=a;
    }
    return ans;
}
signed main()
{
    IOS
    int a,b;cin>>a>>b;
    cout << pow(a,b)+pow(b,a)<<endl;
}