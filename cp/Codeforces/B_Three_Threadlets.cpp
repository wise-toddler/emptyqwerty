// https://codeforces.com/contest/1881/problem/B
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
bool isok(vi a)
{   
    if (a[2]==3*a[0] && a[1]==2*a[0]) // 1 2 3
        return 1;
    if (a[2]==a[1] && a[1]==a[0]) // 1 1 1
        return 1;
    if (a[2]==2*a[1] && a[1]==a[0]) // 1 1 2
        return 1;
    if (a[2]==3*a[1] && a[1]==a[0]) // 1 1 3
        return 1;
    if (a[2]==a[1] && a[1]==2*a[0]) // 1 2 2
        return 1;
    if (a[2]==4*a[1] && a[1]==a[0]) // 1 1 4
        return 1;

    return 0;
    
}
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        vi a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(all(a));
        bool ok = isok(a);
        cout << (ok?"YES":"NO") << endl;

    }
}