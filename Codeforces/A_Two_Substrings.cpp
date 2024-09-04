// https://codeforces.com/contest/550/problem/A
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
void solve()
{
    string s;cin >> s;
    int cab=0,cba=0,caba=0,cbab=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i] == 'A' && s[i+1] == 'B')
        {
            if(i+2 < s.size() && s[i+2] == 'A') caba++,i+=2;
            else cab++,i++;
        }
        if(s[i] == 'B' && s[i+1] == 'A') 
        {
            if(i+2 < s.size() && s[i+2] == 'B') cbab++,i+=2;
            else cba++,i++;
        }
    }
    // deb(cab)deb(cba)deb(caba)deb(cbab)
    if(cab && cba) cout << "YES";
    else if(caba>1 || cbab>1 || ((caba+cbab)>1)) cout << "YES";
    else if((cab || cba) && (cbab || caba)) cout << "YES";
    else cout << "NO";
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}