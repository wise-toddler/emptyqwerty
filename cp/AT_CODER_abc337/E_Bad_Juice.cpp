// https://atcoder.jp/contests/abc337/tasks/abc337_e
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
template<typename T>ostream& operator<<(ostream& os, v<v<T>>& v){for(auto& x : v)os << x << endl;return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
int ba(string a)
{
    int n=a.size();
    int ans=0;
    fon(i,n)
        if(a[i]=='1')
            ans+=1<<(n-i-1);
    
    return ans;
}
void solve()
{
    int n;cin>>n;
    int fc=(int)log2(n-1)+1;
    // cout << fc << '\n';
    vi ans(n);
    fon(i,n) ans[i]=i;
    
    fon(j,0)
    {
        int mx=0;
        fon(i,n)
            if(i&(1<<j))
                mx++;

        cout << mx << " ";
            
        fon(i,n)
            if(i&(1<<j))
                cout << (i+1) <<" ";
        nl
    } 
    string a; cin >> a;

    // cout << a<<" ";
    reverse(all(a));
    // cout << ba(a)+1 << endl;
    vvi aa(5,vi(5,0));
    cout << aa << endl;
}
signed main()
{
    // IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}