// https://www.codechef.com/START112B/problems/LOGICIAN
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
int e=0;
void solve()
{
    int n; cin >> n;
    // cout << n <<" \n";
    // vi a(n); cin>> a;
    string a;cin >>a;
    // vector<string> ans(n,"");
    int id=n,i=0;
    for(i=0;i<n-1;i++)
    {
        if(a[i]!='0')
            cout << "IDK"<<'\n';
        else
        {
            id=i;
            break;
        }
    }
    if(id==n)
    {
        if(a[n-1]=='0')
            cout << "NO"<<'\n';
        else    
            cout << "YES"<<'\n';
        return;
    }
    for(int i=id;i<n;i++)
        cout << "NO" <<'\n';
    



    // for(int i)
    // cout << id<<'\n';
}
signed main()
{
    // IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
        // cout<<'\n';
    }
}