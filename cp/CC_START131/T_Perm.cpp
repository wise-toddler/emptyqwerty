// https://www.codechef.com/START131B/problems/TPERM
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
void solve()
{
    int n;cin >> n;
    if((n%3==0) || (n%3==1))
    {
        fo1(i,1,n+1,1)
        {
            int num;
            if(i%3==1) 
                num=i;
            else if(i%3==0)
                num=i-1;
            else
                num=i+1;
                
            cout << num << " ";        
        }
    }
    else
    {
        // print 4 5 2 1 3
        cout << 4 << " " << 5 << " " << 2 << " " << 1 << " " << 3 << " ";
        fo1(i,6,n+1,1)
        {
            int num;
            if(i%3==1) num=i;
            else if(i%3==0) num=i+2;
            else num=i-2;
            cout << num << " ";         
        }
    }
    nl
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