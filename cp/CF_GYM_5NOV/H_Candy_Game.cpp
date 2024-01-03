// https://codeforces.com/gym/104759/problem/H
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
// powers of 2 till 1e18
bool inrange(int k,int d,int a) {return k<=a && a<=k+d;}
vi powers;
void p2()
{
    int i=1;
    while(i<=1e18)
    {
        powers.pb(i);
        i*=2;
    }
}
void solve()
{
    int n,k,d;cin>>n>>k>>d;
    if(k+d>n) d = n-k;
    int pp = 1,e=0;
    pp = pow(2,(int)log2(n));
    // cout << log
    e = ceil(log2(n));
    // deb(pp)
    // deb(e)
    int ans = 2*(n-pp)+1;
    // deb(ans)

    // if(ans-pp<=0 && ans+pp>n)e--;
    // cout <<(n==k) << endl;
    while(pp>0)
    {
        int ln = ans;
        while(ln+pp<=n)
        {
            ln+=pp;
        }
        while(ln-pp>0)
        {
            if(inrange(k,d,ln))
            {
                goto here;
            }
            ln-=pp;
        }
        // if(!(ans+pp>n && ans-pp<=0))
        e--;
        pp/=2;
    }
    here:
    cout << e<< endl;

}
signed main()
{
    IOS
    //TxtIO
    p2();
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}