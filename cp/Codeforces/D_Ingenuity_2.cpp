// https://codeforces.com/contest/1974/problem/D
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
void solve()
{
    int n;cin >> n;
    string s;cin >> s;
    map<char,int> mp;
    mp['N']=mp['S']=mp['E']=mp['W']=0;
    bool oo =0;
    for(auto &x:s) mp[x]++;
    // int mi = INT_MAX;
    // for(auto &x:mp) mi=min(mi,x.ss);
    // for(auto &x:mp) x.ss-=mi;
    // cout << mp['N'] << " " << mp['S'] << " " << mp['E'] << " " << mp['W'] << endl;
    // deb(mi);
    if((mp['N']+mp['S'])&1 || (mp['E']+mp['W'])&1)
    {
        cout << "NO" << endl;
        return;
    }
    
    // string ans(n,'*');
    auto f=[&](int i,string p)
    {
        for(char x:p)
        {
            int as=i;
            for(auto &y:s)
            {
                if(y==x)
                {
                    if(p=="NS") y=(as==i?'R':'H');
                    else y=(as==i?'H':'R');
                    as--;
                }
                if(as==0) break;
            }
        }
    };

    int mins = min(mp['N'],mp['S']);
    int miew = min(mp['E'],mp['W']);

    oo |= (mins+miew)>=2;
    // cout << oo << " " << s << endl;
    mp['N']-=mins;
    mp['S']-=mins;
    mp['E']-=miew;
    mp['W']-=miew;
    // f(mi,"NSWE");
    if(mins) f(mins,"NS");
    if(miew) f(miew,"WE");
    // cout << s << endl;
    // deb(mins);
    // deb(miew);
    int a1=mp['N'],a2=mp['S'],a3=mp['E'],a4=mp['W'];
    auto g = [&](int i,char x,string p)
    {
        oo|=(i!=0);
        // cout << oo << endl;
        for(auto &y:p)
        {
            int as=i;
            for(auto &z:s)
            {
                if(z==y)
                {
                    as--;
                    z=x;
                }
                if(as==0) break;
            }
        }
    };
    g(a1/2,'H',"N");
    g(a2/2,'H',"S");
    g(a3/2,'H',"E");
    g(a4/2,'H',"W");

    g(a1/2,'R',"N");
    g(a2/2,'R',"S");
    g(a3/2,'R',"E");
    g(a4/2,'R',"W");

    if(!oo) 
        cout << "NO" << endl;
    else 
        cout << s << endl;
    
}
string solve(string s)
{
    // int n;cin >> n;
    // string s;cin >> s;
    map<char,int> mp;
    mp['N']=mp['S']=mp['E']=mp['W']=0;
    bool oo =0;
    for(auto &x:s) mp[x]++;

    if((mp['N']+mp['S'])&1 || (mp['E']+mp['W'])&1)
    {
        return "NO";
    }
    
    // string ans(n,'*');
    auto f=[&](int i,string p)
    {
        for(char x:p)
        {
            int as=i;
            for(auto &y:s)
            {
                if(y==x)
                {
                    if(p=="NS") y=(as==i?'R':'H');
                    else y=(as==i?'H':'R');
                    as--;
                }
                if(as==0) break;
            }
        }
    };

    int mins = min(mp['N'],mp['S']);
    int miew = min(mp['E'],mp['W']);

    oo |= (mins+miew)>=2;
    // cout << oo << " " << s << endl;
    mp['N']-=mins;
    mp['S']-=mins;
    mp['E']-=miew;
    mp['W']-=miew;
    // f(mi,"NSWE");
    f(mins,"NS");
    f(miew,"WE");
    // cout << s << endl;
    int a1=mp['N'],a2=mp['S'],a3=mp['E'],a4=mp['W'];
    auto g = [&](int i,char x,string p)
    {
        oo|=(i!=0);
        // cout << oo << endl;
        for(auto &y:p)
        {
            int as=i;
            for(auto &z:s)
            {
                if(z==y)
                {
                    as--;
                    z=x;
                }
                if(as==0) break;
            }
        }
    };
    g(a1/2,'H',"N");
    g(a2/2,'H',"S");
    g(a3/2,'H',"E");
    g(a4/2,'H',"W");

    g(a1/2,'R',"N");
    g(a2/2,'R',"S");
    g(a3/2,'R',"E");
    g(a4/2,'R',"W");

    if(!oo) 
        return "NO";
    else 
        return s;
    
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
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
    // int tc=100;
    // auto genstr = [&](int n)
    // {
    //     string s;
    //     for(int i=0;i<n;i++)
    //         s+=((rand()%4)==0?'N':(rand()%4)==1?'S':(rand()%4)==2?'E':'W');
        
    //     return s;
    // };
    // vector<tuple<string,string,bool>> v;
    auto check = [&](string s,string ans)
    {
        int n=s.size();
        pii r={0,0},h={0,0};
        fon(i,n)
        {
            if(ans[i]=='H')
            {
                if(s[i]=='N') r.ff++;
                if(s[i]=='S') r.ff--;
                if(s[i]=='E') r.ss++;
                if(s[i]=='W') r.ss--;
            }
            else
            {
                if(s[i]=='N') h.ff++;
                if(s[i]=='S') h.ff--;
                if(s[i]=='E') h.ss++;
                if(s[i]=='W') h.ss--;
            }
        }
        return r.ff==h.ff && r.ss==h.ss;
    };
    // cout << check("SSSSWW","RHHHHR") << endl;

    // while(tc--)
    // {
    //     string s = genstr(rand()%100+1);
    //     string ans = solve(s);
    //     if(ans=="NO") continue;
    //     v.pb({s,ans,check(s,ans)});
    // }
    // for(auto [x,y,z]:v)
    // {
    //     cout << x << " " << y << " " << z << endl;
    // }
}