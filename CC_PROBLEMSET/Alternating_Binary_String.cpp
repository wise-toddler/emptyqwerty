// https://www.codechef.com/START130B/problems/ALBS
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
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
int s_0(string s)
{
    int cnt=0;
    fon(i,s.size())
    {
        if(i&1)
        {
            if((s[i]-'0')^(cnt&1)==0) cnt++;
        }
        else
        {
            if(((s[i]-'0')^(cnt&1))==1) cnt++;
        }
    }
    return cnt;
}
int s_1(string s)
{
    int cnt=0;
    fon(i,s.size())
    {
        if(i&1)
        {
            if((s[i]-'0')^(cnt&1)==1) cnt++;
        }
        else
        {
            if(((s[i]-'0')^(cnt&1))==0) cnt++;
        }
    }
    return cnt;
}
void solve()
{
    int n;cin >> n;
    string s;cin >> s;
    int cnt=s_0(s);
    int cnt_=s_1(s);
    cout << min(cnt,cnt_) << endl;
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