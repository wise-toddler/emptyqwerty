// https://codeforces.com/contest/1978/problem/E
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
#define sz(x) (int)x.size()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    string t;cin>>t;

    string ns=s,nt=t;
    fon(i,n-2) 
    {
        if(ns[i]=='0' and ns[i+2]=='0') nt[i+1]='1';    
    }
    fon(i,n-2) 
    {
        if(nt[i]=='1' and nt[i+2]=='1') ns[i+1]='1';    
    }
    // deb(ns)
    // deb(nt)
    // nl
    vi pre(n);
    pre[0]=(ns[0]=='1');
    fo1(i,1,n,1) pre[i]=pre[i-1]+(ns[i]=='1');
    auto sum = [&](int l,int r)
    {
        if(l==0) return pre[r];
        return pre[r]-pre[l-1];
    };
    // deb(pre);

    int q;cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        l--;r--;
        int len = r-l+1;
        if(len==1)
        {
            cout << (s[l]=='1') << endl;
            continue;
        }
        if(len==2)
        {
            // deb(s)
            // deb(l) deb(r)
            // deb(s[l]) deb(s[r])
            cout << ((s[l]=='1') + (s[r]=='1')) << endl;
            continue;
        }
        if(len==3)
        {
            int ans = (s[l]=='1') + (s[r]=='1') + (s[l+1]=='1' || ((t[l]=='1') and (t[l+2]=='1')));
            cout << ans << endl;
            continue;
        }
        if(len<=10)
        {
            int ans=(s[l]=='1') + (s[r]=='1');
            string ss= s,tt=t;
            fo1(i,l+1,r,1) 
            {
                if(ss[i-1]=='0' and ss[i+1]=='0') tt[i]='1';    
            }
            fo1(i,l+1,r,1) ans += ss[i]=='1' || (tt[i-1]=='1' and tt[i+1]=='1'); 
            cout << ans << endl;
            continue;   
        }
        // take ans of l+2 to r-2 from preprocess 
        // the process the l,l+1, and r-1,r 
        // deb(s.substr(l,r-l+1))
        // deb(t.substr(l,r-l+1))
        // deb(ns.substr(l,r-l+1))
        // int ans=sum(l+2,r-2);
        // ans += s[l]=='1';
        // ans += (s[l+1]=='1' || (t[l]=='1' and t[l+2]=='1'));
        // ans += s[r]=='1';
        // ans += (s[r-1]=='1' || (t[r]=='1' and t[r-2]=='1'));
        // cout << ans << endl;
        string fps=s.substr(l,4);
        string fst=t.substr(l,4);
        fo1(i,1,3,1)
        {
            if(fps[i-1]=='0' and fps[i+1]=='0') fst[i]='1';    
        }
        int ans = (fps[0]=='1');
        fo1(i,1,2,1) ans += (fps[i]=='1' || (fst[i-1]=='1' and fst[i+1]=='1'));
        // deb(ans)
        fps=s.substr(r-3,4);
        fst=t.substr(r-3,4);
        fo1(i,1,3,1)
        {
            if(fps[i-1]=='0' and fps[i+1]=='0') fst[i]='1';    
        }
        ans += (fps[3]=='1');
        fo1(i,2,3,1) ans += (fps[i]=='1' || (fst[i-1]=='1' and fst[i+1]=='1'));
        ans += sum(l+2,r-2);
        cout << ans << endl;// https://codeforces.com/contest/1978/problem/E
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
#define sz(x) (int)x.size()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    string t;cin>>t;

    string ns=s,nt=t;
    fon(i,n-2) 
    {
        if(ns[i]=='0' and ns[i+2]=='0') nt[i+1]='1';    
    }
    fon(i,n-2) 
    {
        if(nt[i]=='1' and nt[i+2]=='1') ns[i+1]='1';    
    }
    // deb(ns)
    // deb(nt)
    // nl
    vi pre(n);
    pre[0]=(ns[0]=='1');
    fo1(i,1,n,1) pre[i]=pre[i-1]+(ns[i]=='1');
    auto sum = [&](int l,int r)
    {
        if(l==0) return pre[r];
        return pre[r]-pre[l-1];
    };
    // deb(pre);

    int q;cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        l--;r--;
        int len = r-l+1;
        if(len==1)
        {
            cout << (s[l]=='1') << endl;
            continue;
        }
        if(len==2)
        {
            // deb(s)
            // deb(l) deb(r)
            // deb(s[l]) deb(s[r])
            cout << ((s[l]=='1') + (s[r]=='1')) << endl;
            continue;
        }
        if(len==3)
        {
            int ans = (s[l]=='1') + (s[r]=='1') + (s[l+1]=='1' || ((t[l]=='1') and (t[l+2]=='1')));
            cout << ans << endl;
            continue;
        }
        if(len<=10)
        {
            int ans=(s[l]=='1') + (s[r]=='1');
            string ss= s,tt=t;
            fo1(i,l+1,r,1) 
            {
                if(ss[i-1]=='0' and ss[i+1]=='0') tt[i]='1';    
            }
            fo1(i,l+1,r,1) ans += ss[i]=='1' || (tt[i-1]=='1' and tt[i+1]=='1'); 
            cout << ans << endl;
            continue;   
        }
        // take ans of l+2 to r-2 from preprocess 
        // the process the l,l+1, and r-1,r 
        // deb(s.substr(l,r-l+1))
        // deb(t.substr(l,r-l+1))
        // deb(ns.substr(l,r-l+1))
        // int ans=sum(l+2,r-2);
        // ans += s[l]=='1';
        // ans += (s[l+1]=='1' || (t[l]=='1' and t[l+2]=='1'));
        // ans += s[r]=='1';
        // ans += (s[r-1]=='1' || (t[r]=='1' and t[r-2]=='1'));
        // cout << ans << endl;
        string fps=s.substr(l,4);
        string fst=t.substr(l,4);
        fo1(i,1,3,1)
        {
            if(fps[i-1]=='0' and fps[i+1]=='0') fst[i]='1';    
        }
        int ans = (fps[0]=='1');
        fo1(i,1,2,1) ans += (fps[i]=='1' || (fst[i-1]=='1' and fst[i+1]=='1'));
        // deb(ans)
        fps=s.substr(r-3,4);
        fst=t.substr(r-3,4);
        fo1(i,1,3,1)
        {
            if(fps[i-1]=='0' and fps[i+1]=='0') fst[i]='1';    
        }
        ans += (fps[3]=='1');
        fo1(i,2,3,1) ans += (fps[i]=='1' || (fst[i-1]=='1' and fst[i+1]=='1'));
        ans += sum(l+2,r-2);
        cout << ans << endl;
    }
    // nl
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
    }
    // nl
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