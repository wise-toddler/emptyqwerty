// https://codeforces.com/contest/2004/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define nl cout << endl;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define v vector
#define vi vector<int>
#define vvi vector<vector<int>>
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
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T> v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    // BGRY
    auto get2 = [&](char a,char b)
    {
        if(a=='B' and b=='G') return 0;
        if(a=='B' and b=='R') return 1;
        if(a=='B' and b=='Y') return 2;
        if(a=='G' and b=='R') return 3;
        if(a=='G' and b=='Y') return 4;
        if(a=='R' and b=='Y') return 5;
        return -1;
    };
    int n,q;cin >> n >> q;
    vi aa(n);
    vvi mynode(6,vi(n));
    vvi adj = {{1,2,3,4},{0,2,3,5},{0,1,4,5},{0,1,4,5},{0,2,3,5},{1,2,3,4}};

    fon(i,n)
    {
        char a,b;cin >> a >> b;
        int pos = get2(a,b);
        if(pos==-1) pos=get2(b,a);
        aa[i]=pos;
        mynode[pos][i]=1;
    }
    // print mynode
    // fon(i,6)
    // {
    //     cout << "mynode[" << i << "]: " ;
    //     for(auto x : mynode[i]) cout << x << " ";
    //     cout << endl;
    // }
    // nearest B right , nearest B left
    // nearest G right , nearest G left
    // nearest R right , nearest R left
    // nearest Y right , nearest Y left
    vvi nearestleft(6,vi(n,-1));
    vvi nearestright(6,vi(n,-1));
    fon(i,6)
    {
        int last=-1;
        fon(j,n)
        {
            if(mynode[i][j]) last=j;
            nearestleft[i][j]=last;
        }
        last=-1;
        fon_(j,n)
        {
            if(mynode[i][j]) last=j;
            nearestright[i][j]=last;
        }
    }
    // print nearestleft
    // fon(i,6)
    // {
    //     cout << "nearestleft[" << i << "]: " << nearestleft[i] << endl;
    //     cout << "nearestright[" << i << "]: " << nearestright[i] << endl;
    // }
    // query
    // deb(aa);
    // deb(adj);
    while(q--)
    {
        int l,r;cin >> l >> r;
        l--,r--;
        if(l>r) swap(l,r);
        bool disjoint=1;
        if(aa[l]==aa[r]) disjoint=0;
        
        for(auto i:adj[aa[l]])
        {
            if(i==aa[r])
            {
                disjoint=0;
                break;
            }
        }
        // deb(disjoint)
        if(!disjoint)
        {
            cout << r-l << endl;
            continue;
        }
        // disjoint
        int ans=LLONG_MAX;
        for(auto p: adj[aa[l]]) 
        {
            int left=nearestleft[p][r];
            int right=nearestright[p][r];
            if(left!=-1) 
            {
                ans=min(ans,abs(l-left)+abs(r-left));   
            }
            if(right!=-1) 
            {
                ans=min(ans,abs(l-right)+abs(r-right));
            }
            // deb(ans) 
        }
        for(auto p: adj[aa[r]])
        {
            int left=nearestleft[p][l];
            int right=nearestright[p][l];
            if(left!=-1) 
            {
                ans=min(ans,abs(l-left)+abs(r-left));   
            }
            if(right!=-1) 
            {
                ans=min(ans,abs(l-right)+abs(r-right));
            }
            // deb(ans)
        }

        if(ans==LLONG_MAX) ans=-1;
        cout << ans << endl;
    }
    
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