// https://codedrills.io/contests/icpc-india-preliminary-2023/problems/uno-problem
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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    // if(u = normalcard, r=reversecard, s=skip)
    int dir=1;
    int ans=0;
    for(char c : s)
    {
        if(c=='U')
        {
            ans+=dir;
        }
        else if(c=='R')
        {
            dir*=-1;
            ans+=dir;
        }
        else if(c=='S')
        {
            ans+=2*dir;
        }
        ans=(ans+n)%n;
    }
    cout << (ans+1) << endl;
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