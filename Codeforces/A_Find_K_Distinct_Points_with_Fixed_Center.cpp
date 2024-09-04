// https://codeforces.com/contest/1998/problem/0
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
void solve()
{
    int x,y,k;cin >> x >> y >> k;
    vi ax(k),ay(k); 
    // sumof ax=x*k and sumof ay=y*k
    int sumx=0,sumy=0; 
    fon(i,k)
    {
        // can be -ve should be int and distict
        if(k&1)
        {
            ax[i]=x+(i-(k/2));
            ay[i]=y+(i-(k/2));
        }
        else
        {
            if(i<k/2)
            {
                ax[i]=x+(i-(k/2));
                ay[i]=y+(i-(k/2));
            }
            else
            {
                ax[i]=x+(i-(k/2)+1);
                ay[i]=y+(i-(k/2)+1);
            }
        }
        sumx+=ax[i];
        sumy+=ay[i];
    }
    // deb(ax);
    // deb(ay);
    // deb(sumx);
    // deb(sumy);

    fon(i,k) cout << ax[i] << ' ' << ay[i] << endl;

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