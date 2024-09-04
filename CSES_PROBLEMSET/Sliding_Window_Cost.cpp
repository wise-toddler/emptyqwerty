// https://cses.fi/problemset/task/1077
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
class runningmedian
{
public:
    multiset<int> left,right;
    int suml=0,sumr=0;
    void balance()
    {
        if(left.size()>right.size()+1)
        {
            sumr+=*left.rbegin();
            right.insert(*left.rbegin());
            suml-=*left.rbegin();
            left.erase(left.find(*left.rbegin()));
        }
        else if(right.size()>left.size())
        {
            suml+=*right.begin();
            left.insert(*right.begin());
            sumr-=*right.begin();
            right.erase(right.find(*right.begin()));
        }
    }
    void insert(int val)
    {
        if(left.empty() || val<=*left.rbegin()) 
        {
            left.insert(val);
            suml+=val;
        }
        else
        {
            right.insert(val);
            sumr+=val;
        }
        balance();
    }
    int getmedian()
    {
        return *left.rbegin();
    }
    void erase(int val)
    {
        if(left.find(val)!=left.end()) 
        {
            suml-=val;
            left.erase(left.find(val));
        }
        else
        {
            sumr-=val;
            right.erase(right.find(val));
        }
        balance();
    }
    pii getsum()
    {
        return {suml,sumr};
    }
    int size()
    {
        return left.size()+right.size();
    }   
    pii getsize()
    {
        return {left.size(),right.size()};
    }
};
void solve()
{
    int n,k;cin>>n>>k;
    vi a(n);cin>>a;
    runningmedian rm;
    fon(i,n)
    {
        rm.insert(a[i]);
        if(rm.size()==k)
        {
            auto [s1,s2]=rm.getsize();
            int md=rm.getmedian();
            auto [su1,su2]=rm.getsum();
            int sm = s1*md-su1+su2-s2*md;
            cout << sm << ' ';
            rm.erase(a[i-k+1]);
        }
    }    

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