// https://codeforces.com/contest/1907/problem/B
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

bool isUpp(char c)
{
    return c>='A' && c<='Z';
}
bool isLow(char c)
{
    return c>='a' && c<='z';
}
void solve()
{
    string s;cin>>s;
    int n=s.size();
    stack<pair<int,char>> u;
    stack<pair<int,char>> l;
    
    for(int i=0;i<n;i++)
    {
        char c=s[i];
        if(c=='B')
        {
            if(!u.empty())
                u.pop();
        }
        if(c=='b')
        {
            if(!l.empty())
                l.pop();
        }
        if(isUpp(c) && c!='B')
        {  
            u.push({i,c});
        }
        if(isLow(c) && c!='b')
        {
            l.push({i,c});
        }
    }

    string ans="";
    while(!u.empty() && !l.empty())
    {
        if(u.top().first>l.top().first)
        {
            ans+=u.top().second;
            u.pop();
        }
        else
        {
            ans+=l.top().second;
            l.pop();
        }
    }
    while(!u.empty())
    {
        ans+=u.top().second;
        u.pop();
    }
    while(!l.empty())
    {
        ans+=l.top().second;
        l.pop();
    }
    reverse(all(ans));
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