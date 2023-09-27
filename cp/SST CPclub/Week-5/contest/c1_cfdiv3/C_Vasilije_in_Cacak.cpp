// https://codeforces.com/contest/1878/problem/C
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
int f(int n) {return (n*(n+1))/2;}
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int n,k,x;cin >> n >> k >> x;
        bool ok = f(k) <=x and f(n) - f(n-k) >= x;
        cout << (ok?"YES":"NO") << endl;
    }
}