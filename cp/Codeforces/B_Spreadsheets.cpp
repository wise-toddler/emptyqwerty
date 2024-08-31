// https://codeforces.com/problemset/problem/1/B
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
void f1(string &a)
{
    // s=RxCy extract x and y   
    int i=0;
    while(a[i]!='C') i++;
    string X=a.substr(1,i-1);
    string Y=a.substr(i+1);
    int x=stoll(X);
    int y=stoll(Y);
    string ans="";
    while(y>0)
    {
        y--;
        ans+=char('A'+y%26);
        y/=26;
    }
    reverse(all(ans));
    cout << ans << x << endl;
}
void f2(string &a)
{
    int n=a.size();
    int i=0;
    while(a[i]>='A' && a[i]<='Z') i++;
    string X=a.substr(0,i);     
    string Y=a.substr(i);
    int x=0;
    int y=0;
    for(auto c:X) x=x*26+(c-'A'+1);
    y=stoll(Y);
    cout << "R" << y << "C" << x << endl;
}
void solve()
{           
    string s;cin >> s;
    // RxCy
    if(s[0]=='R' && s[1]>='0' && s[1]<='9' && s.find('C')!=string::npos) f1(s);
    else f2(s);
    
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--) solve();
    
}