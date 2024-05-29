// https://codeforces.com/contest/1863/problem/D
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << '\n';return os;}

v<string> a;
int n,m;
bool oddcheck()
{
    int c=0;
    fon(i,n)
    {
        c=0;
        fon(j,m) if(a[i][j]!='.') c++;
        if(c%2) return 1;
    }
    fon(j,m)
    {
        c=0;
        fon(i,n) if(a[i][j]!='.') c++;
        if(c%2) return 1;
    }
    return 0;
}
void solve()
{
    cin>>n>>m;
    a.resize(n);cin >> a;
    if(oddcheck()) {cout << "-1" << endl;return;}
    v<string> b(n,string(m,'.'));
    vi cc(m,0),rr(n,0);
    fon(i,n)
    {
        fon(j,m)
        {
            if(a[i][j]=='.' || b[i][j]!='.') continue;
            if(a[i][j]=='L') // mark the next L in row as !b[i][j]
            {
                bool f=0;
                if(b[i][j]=='.')
                {
                    b[i][j]='W';
                    f=1;
                }
                int k=i+1;
                while(k<n && a[k][j]!='L') k++;
                if(k==n) continue; // no L found
                b[k][j]=f?'B':'W';
            }
            if(a[i][j]=='U') // mark the next U in column as !b[i][j]
            {
                bool f=0;
                if(b[i][j]=='.')
                {
                    b[i][j]='B';
                    f=1;
                }
                int k=j+1;
                while(k<m && a[i][k]!='U') k++;
                if(k==m) continue; // no U found
                b[i][k]=f?'W':'B';
            }
            if(a[i][j]=='R') b[i][j]=b[i][j-1]=='W'?'B':'W';
            if(a[i][j]=='D') b[i][j]=b[i-1][j]=='W'?'B':'W';
        }
    }
    cout << b;
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