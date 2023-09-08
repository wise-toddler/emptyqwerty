// https://codeforces.com/group/isP4JMZTix/contest/386415/problem/F
// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-2/Set-1.md

#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>

// void print(vi a)
// {
//     for(int i =0;i<a.size();i++)
//         cout<<a[i]<<" ";
// }
// void print(vii a)
// {
//     for(int i =0 ;i<a.size();i++)
//     {
//         print(a[i]);
//         cout << endl;
//     }
// }

signed main()
{
    set<int> ans;
    int n, m;cin>>n>>m;
    vi v(n);
    for(int i =0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        ans.insert(v[i]);
        v[i]=ans.size();
    }
    
    // print(v);
    while(m--)
    {
        int qq;cin >> qq;
        cout << v[qq-1] << endl;
    }

}