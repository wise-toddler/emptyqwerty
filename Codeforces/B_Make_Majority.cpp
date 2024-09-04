// https://codeforces.com/contest/1988/problem/B
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
bool solve()
{
    int n;cin>> n;
    string s;cin>>s;
    // cout << s<< endl;
    int count = 0;
    string ss="";
    int mx=0;
    int c=0;
    int c0=0,c1=0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            // co++;
            count++;
            mx=max(mx,c);
            c=0;
        } else {
            if(count) ss+="0";
            count=0;
            ss+='1';
            c++;
            // c1++;
        }
    }
    if(count) ss+="0";
    for(auto i:ss) 
    if(i=='0') c0++;
    else c1++;
    mx=max(mx,c);
    if(c1>c0) return 1;
    if(mx>=3) return 1;
    // cout << c << "\n";
    if(ss.front()=='1' and ss.back()=='1') return 1;
    if((ss.front()-'0'+ss.back()-'0')==1) return mx>=2;
    // cout << ss << endl; // 1011010 
    return 0;
}
signed main()
{
    // 0001011
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        // solve();
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}