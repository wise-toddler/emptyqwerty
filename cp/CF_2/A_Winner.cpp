// https://codeforces.com/contest/2/problem/A
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
class UniqueContainer 
{
public:
    set<string> m_set;
    v<string> ve;
    void insert(string x) {
        if(m_set.find(x) == m_set.end()) {
            m_set.insert(x);
            ve.push_back(x);
        }
    }
};
void solve()
{
    int n;cin >> n;
    map<string,pair<int,v<pair<int,int>>>> m;
    map<int,UniqueContainer> m2;
    fon(i,n)
    {
        string s;int x;cin >> s >> x;
        m[s].ff+=x;
        m2[m[s].ff].insert(s);
        if(m[s].ss.empty()) m[s].ss.pb({m[s].ff,i});
        else 
        {
            if(m[s].ss.back().ff<m[s].ff) m[s].ss.pb({m[s].ff,i});
            else m[s].ss.pb({m[s].ss.back().ff,i});
        }
    }
    int maxx = 0;
    for(auto i:m) maxx = max(maxx,i.ss.ff);
    string ans = "";
    int li=n;
    // deb(maxx);
    // deb(m2[maxx].ve);
    for(auto i:m2[maxx].ve)
    {
        // cout << i << " ";
        if(m[i].ff==maxx)
        {
            // deb(i);
            // cout << "m[i].ss: \n";
            // for(auto [x,y]:m[i].ss) cout << x << " " << y << " \n";
            // deb(m[i].ss)
            int temp = m[i].ss[lower_bound(all(m[i].ss),make_pair(maxx,0LL))-m[i].ss.begin()].ss;

            // deb(temp);
            // deb(li);    
            if(temp<li)
            {
                li = temp;
                ans = i;
            }
            // deb(li);
            // deb(ans);
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}
