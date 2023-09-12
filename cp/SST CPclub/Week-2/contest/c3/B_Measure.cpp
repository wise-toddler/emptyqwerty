// https://atcoder.jp/contests/abc319/tasks/abc319_b 
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

int gcd(int a,int b){return a%b==0?b:gcd(b,a%b);}

signed main()
{
    IOS
    int n;cin>>n;
    cout << 1;
    for (int i = 1; i <=n; i++)
    {
        int q = gcd(n-i,i);
        if(n%q==0 && n/q <10)
            cout<<n/q;
        else 
            cout<<'-';
    }
}