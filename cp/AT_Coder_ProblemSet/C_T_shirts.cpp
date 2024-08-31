// https://atcoder.jp/contests/abc332/tasks/abc332_c
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
    // split the string whereever there is a 0
vector<string> split(string s,char c)
{
    // ignore the first 0s and last 0s
    int n = s.size();
    int st=0,en=n-1;
    while(s[st]==c) st++;
    while(s[en]==c) en--;
    vector<string> ans;
    string temp="";
    fo1(i,st,en+1,1)
    {
        if(s[i]==c)
        {
            ans.pb(temp);
            temp="";
        }
        else
        {
            temp+=s[i];
        }
    }
    if(temp!="") ans.pb(temp);
    return ans;
}
void solve()
{
    int n,m;cin >> n >> m;
    string s;cin >> s;
    // cout << s << endl;
    vector<string> a=split(s,'0');
    int ans1=0,ans2=0;
    for(auto i:a)
    {
        // count 1s and 2s
        int one=0,two=0;
        for(auto j:i)
        {
            if(j=='1') one++;
            else two++;
        }
        ans2=max(ans2,max(two,max(0LL,(int)i.size()-m)));
    }
    cout << ans2 << endl;
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
    }
}