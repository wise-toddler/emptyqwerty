// https://codeforces.com/contest/2004/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define nl cout << endl;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define v vector
#define vi v<int>
#define vvi v<v<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    // if disjoint
    if(l1>l2) swap(l1,l2),swap(r1,r2);
    if(r1 < l2 or r2 < l1)
    {
        cout << 1 << endl;
    }
    else if(l1==l2 and r1==r2) // equal
    {
        cout << r1-l1 << endl;
    }
    else if(l1 == l2) // l1 is equal
    {
        int r=min(r1,r2);
        cout << r-l1+1 << endl;
    }
    else if(r1 == r2) // r1 is equal
    {
        int l=max(l1,l2);
        cout << r1-l+1 << endl;
    }
    else if(r1 > r2) // l1 is subset of l2
    {
        cout << r2-l2 + 2 << endl;
    }
    else 
    {   
        cout << r1 - l2 + 2 << endl;
    }
    // // cout  the common part length
    // int l=max(l1,l2),r=min(r1,r2);
    // // cout << l << " " << r << endl;
    // cout << r-l << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}