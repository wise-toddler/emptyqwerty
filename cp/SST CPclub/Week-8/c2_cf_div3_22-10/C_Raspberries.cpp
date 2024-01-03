// https://codeforces.com/contest/1883/problem/C
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define deb(x) cout << #x << ": " << x << endl;
void solve()
{
    int n,k;
    cin >> n >> k;
    vi a(n);
    for(int &x:a)cin>>x;
    map<int,int> mp;
    for(int &x:a)
    {
        mp[x%k]++;
    }
    if(mp[0])
    {
        cout << 0 << endl;
        return;
    }
    if(k==2)
    {
        cout << 1 << endl;
        return;
    }
    if(k==3)
    {
        if(mp[2])
        {
            cout << 1 << endl;
            return;
        }
        if(mp[1])
        {
            cout << 2 << endl;
            return;
        }
        return; 
    }
    if(k==5)
    {
        cout << (mp[0]?0:(mp[4]?1:(mp[3]?2:(mp[2]?3:4)))) << endl;
        return;
    }
    if(k==4)
    {
        if(mp[0] || mp[2]>=2)
        {
            cout << 0 << endl;
            return;
        }
        if(mp[3])
        {
            cout << 1 << endl;
            return;
        }
        if(mp[1] && mp[2])
        {
            cout << 1 << endl;
            return;
        }
        if(mp[2])
        {
            cout << 2 << endl;
            return;
        }
        if(mp[1])
        {
        
            cout << (mp[1]>1?2:3) << endl;
            return;
        }
        cout << -1 << endl;
        // return;
    }

}
signed main()
{
    IOS
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
/*
2 2
2 2
1 1
0 0
2 3
0 0
1 1
2 3
0 0
1 1
1 1
4 4
0 0
4 4
3 3

9 5 1 5 9 5 1
1 1 1 1 1 1 1


*/ 
