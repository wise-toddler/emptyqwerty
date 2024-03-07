// https://www.codechef.com/START117B/problems/EQUAL2
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
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
// set<int> s;
vector<int> s(1e5+1);
void solve()
{
    int a,b;cin>>a>>b;
    if(a==b)
    {
        cout << 0 << endl;
        return;
    }
    if(a>b)
        swap(a,b);
    int d=b-a;
    int ans=0;
    int id=lower_bound(s.begin(),s.end(),d)-s.begin();
    while((s[id]-d)&1)    
        id++;
    cout << id-1 << endl;
}
signed main()
{
    IOS
    int ii=0;
    for(int i=0;i<1e5;i++)
    {
        s[i]=ii;
        ii+=i;
    }
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}