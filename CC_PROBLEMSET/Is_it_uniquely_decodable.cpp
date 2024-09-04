// https://www.codechef.com/START118B/problems/UNIQUEDECODE
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
    string s;cin>>s;
    int n=s.size();
    vector<int> countbfromback(n,0);
    for(int i=n-1;i>=0;i--)
        countbfromback[i]=((i==n-1)?0:countbfromback[i+1])+(s[i]=='b');
    // cout << countbfromback << endl;
    int ca=count(all(s),'a');
    // int cb=n-ca;
    int only1=(1<<ca)-1;
    int only2=0;
    for(int i=0;i<n;i++)
        if(s[i]=='a')
            only2+=countbfromback[i];
    
    
        
    // int only3=0;
    // int only2=(1<<min(ca,cb))-1; // 3_1 
    // int only3=(1<<min(ca/2,cb))-1;
    // // int only1and2 
    // int m=1e9+7;
    deb (only1)
    deb (only2)
    // deb (only3)

    // cout << ((only1+only2)%m+only3)%m << endl;

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