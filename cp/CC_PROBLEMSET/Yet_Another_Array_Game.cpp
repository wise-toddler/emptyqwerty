// https://www.codechef.com/START112B/problems/ARRAYGAME
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
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
int s;
void solve()
{
    int n;cin>>n;
    vi a(n);cin>>a;
    sort(all(a));
    if(n<=2)
    {
        cout << a[n-1];
        return;
    }
    int i=n-3,j=n-1;
    int maxa=a[j];
    int sum=a[j];
    while(i>=0)
    {
        sum-=a[j];
        j--;
        sum+=a[i]+a[i+1];
        i-=2;
        maxa=max(maxa,sum);
    }
    cout << (s?maxa:sum);
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t >> s;
    while(t--)
    {
        solve();
        cout << endl;
    }
}