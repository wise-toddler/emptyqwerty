// https://codeforces.com/problemset/problem/296/C
// https://codeforces.com/problemset/problem/295/A
// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-2/Set-1.md
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
void print(vi v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    cout << endl;
}
void print(vii v)
{
    for(int i=0;i<v.size();i++)
    {
        print(v[i]);
    }
}
signed main()
{
    IOS
    int n,m,k;cin >> n >> m >> k;
    vi v12(n);
    for (int i = 0; i < n; i++)
        cin >> v12[i];

    vii mm(m,vi(3,0));
    for (int i = 0; i < m; i++)
        cin >> mm[i][0] >> mm[i][1] >> mm[i][2]; // making operations array
    // print();

    // while(k--)
    // {
    //     int x1,y1;cin >> x1 >>y1;
    //     while(x1<=y1)
    //     {
    //         long l = mm[x1-1][0];
    //         long r = mm[x1-1][1];
    //         long k = mm[x1-1][2];
    //         v[l-1] += k;
    //         if(r!=n)
    //             v[r] -=k;
    //         x1++;
    //     }
    // }   

    vi kk(m,0);
    for(int i =0;i<k;i++)
    {
        int x1,y1;cin >> x1 >>y1;
        kk[x1-1]+=1;
        if(y1!=m)
            kk[y1]-=1;
    }//differece array for k queries
    for(int i =1;i<m;i++)
        kk[i]=kk[i]+kk[i-1];//presum
    // print(kk);

    vi v(n);
    for (int i = 0; i < m; i++)
    {    
        int l = mm[i][0];
        int r = mm[i][1];
        int d = mm[i][2]*kk[i];
        v[l-1] += d;
        if(r!=n)
            v[r]-=d;
    }
    for(int i =1;i<n;i++)
        v[i]=v[i]+v[i-1];//presum
    for(int i =0;i<n;i++)
        v[i]=v[i]+v12[i];//final addition
    print(v);
}