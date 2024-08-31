// https://www.codechef.com/START141B/problems/WELLLEFT
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
int f(int n)
{
    return n*(n+1)/2;
}
int bf(int n,int k,int h)
{
    int ans=0;
    fon(i,n)
    {
        fon(j,n)
        {
            int c=0;
            int it=0;
            while(it<k)
            {   
                c+=i;
                if(c>=h) break;
                c-=j;
                it++;
            }
            if(c>=h) ans++;
        }
    }
    return ans;
}
void solve()
{
    int n,k,h;
    cin >> n >> k >> h;
    //     return;
    // }
    // cout << bf(n,k,h) << endl; return;

    int md=h/k;
    if(md>=(n-1)) 
    {
        cout << 0 << endl;
        return;
    }
    int mxa=min(n,h-1);
    int mna=max(2ll,md+1);
    // int mxb=mxa-md;
    // int mnb=md;
    int ans=max(0ll,n-mxa)*n;  // 0 mehant needed wala ans 
    // deb(mxa)deb(mna)
    deb(ans)
    ans+=f(mxa-mna+1); // 
    deb(ans)
    ans+=(k-1)*(f(md-1));
    deb(ans)
    cout << ans << endl;
    // int md=(h-a)/k;


    // brute force

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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}

/*
4 1 
5 1 2
6 1 2 3 
7 1 2 3 4 
8 1 2 3 4 5 || 6
9 1 2 3 4 5 6 || 7
10 1 2 3 4 5 6 7 || 8
11 1 2 3 4 5 6 7 8 || 9 
12 1 2 3 4 5 6 7 8 9 || 10 
13 1 2 3 4 5 6 7 8 9 10 || 11 12
14 1 2 3 4 5 6 7 8 9 10 11 || 12 13
15 1 2 3 4 5 6 7 8 9 10 11 12 || 13 14
16 1 2 3 4 5 6 7 8 9 10 11 12 13 || 14 15
17 1 2 3 4 5 6 7 8 9 10 11 12 13 14 || 15 16 

18 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
19 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20


1 
2 
3 1 2
4 1 2 3 
5 1 2 3 4
6 1 2 3 4 5

7 1 2 3 4 5 6 7 8
8 1 2 3 4 5 6 7 8


*/

