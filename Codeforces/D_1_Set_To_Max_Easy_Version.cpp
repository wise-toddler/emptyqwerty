// https://codeforces.com/contest/1904/problem/D1
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
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    vi b(n);cin >> b;

    fo1(i,0,n,1)
    {
        if(a[i]>b[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    if(*max_element(all(a))!=*max_element(all(b)))
    {
        cout << "NO" << endl;
        return;
    }
    stack<int> ss,se;
    fo1(i,n-1,-1,-1)
    {
        if(se.empty())
        {
            se.push(a[i]);
            continue;
        }   
        // if(a[i]>ss.top())
    }

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
    }
}