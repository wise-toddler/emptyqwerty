// https://cses.fi/problemset/task/1644
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

template<typename T>
class segtree
{
public:
    v<T> tree;
    T idn;
    int n;
    T merge(T a,T b)
    {
        // write your merge function here
        pii ans;
        if(a.ff<b.ff) ans={a.ff,a.ss};
        else ans={b.ff,b.ss};
        return ans;
    }
    segtree(int n,T idn)
    {
        this->n=n;
        this->idn=idn;
        tree.assign(4*n,idn);
    }
    void upt(int qidx,T val)
    {
        function <void(int,int,int)> update=[&](int idx,int st,int en)
        {
            if(st==en)
            {
                tree[idx]=val;
                return;
            }
            int mid=(st+en)/2;
            if(qidx<=mid) update(2*idx+1,st,mid);
            else update(2*idx+2,mid+1,en);
            tree[idx]=merge(tree[2*idx+1],tree[2*idx+2]);
        };
        update(0,0,n-1);
    }
    T qry(int l,int r)
    {
        function <T(int,int,int)> query=[&](int idx,int st,int en)
        {
            if(l>en || r<st) return idn; // out of range
            if(l<=st && en<=r) return tree[idx]; // in range
            int mid=(st+en)/2;
            return merge(query(2*idx+1,st,mid),query(2*idx+2,mid+1,en));
        };
        return query(0,0,n-1);
    }
};

void solve()
{
    int n,l,r;cin >> n >> l >> r;
    vi a(n);cin >> a;
    segtree<pii> st(n,{LLO_MAX,0}); // minsum, index
    vi presum(n,0); 
    presum[0]=a[0];
    fo1(i,1,n,1) presum[i]=presum[i-1]+a[i];
    // deb(presum)
    fon(i,n) st.upt(i,{presum[i],i});
    int i=0;
    int c=presum[l-1];
    int ans=c;
    // deb(c)
    auto sum = [&](int i,int j)
    {
        return presum[j]-(i>0?presum[i-1]:0);
    };
    auto sum2 = [&](int j,int l) 
    {
        return presum[j]-(j-l>=0?presum[j-l]:0);
    };
    fo1(j,l,n,1)
    {
        if(j-i<r)
        {   
            // min sum of subarray of length is l 
            if((c+a[j])<sum2(j,l))
            {
                c=sum2(j,l);
                i=j-l+1;        
            }
            else 
            {
                c+=a[j];
            } 
        }
        else
        {
            auto [sum,ni]=st.qry(i+1,j-l);
            c=presum[j]-sum;
            i=ni+1;
        }
        ans=max(ans,c);
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
    }
    return 0;
}