// https://codeforces.com/contest/158/problem/B
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

signed main()
{
    int n;cin>>n;
    vector<int> v(5,0);
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        v[a]++;
    }
    int ans=0;
    ans+=v[4];
    ans+=v[3];
    v[1]=max(0,v[1]-v[3]);
    bool a = v[2]%2!=0;
    ans+=v[2]/2;
    if(a)
    {
        ans++;
        v[1]=max(0,v[1]-2);
    }
    ans+=v[1]/4;
    if(v[1]%4!=0)
        ans++;
    cout << ans<<endl;
}

