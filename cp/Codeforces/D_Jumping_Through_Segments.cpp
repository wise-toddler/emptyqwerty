// https://codeforces.com/contest/1907/problem/D
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

bool ch(const vector<pii> &a, int k)
{
    int minn = 0;
    int maxx = 0;
    for (auto &i : a)
    {
        minn = max(minn, i.first);
        maxx = min(maxx + k, i.second);
        if (minn > maxx) return false;
        minn = max(minn - k, 0LL);
    }
    return true;
}

void solve()
{
    int n;cin>>n;
    vector<pii> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;

    int l=0,r=1e9;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(ch(v,mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }

    cout<<ans<<endl;
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