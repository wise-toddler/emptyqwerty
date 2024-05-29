// https://codeforces.com/problemset/problem/1488/E
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}

int merge(int a, int b) {
    return max(a, b);
}

template < typename T >
class SegmentTree {
    v < v < T >> Tree;
    T neutralValue;
    T query(int level, int idx, int treeLeft, int treeRight, int l, int r) {
        if (treeLeft > treeRight or treeRight < l or treeLeft > r or r < treeLeft or l > treeRight or level == Tree.size())
            return neutralValue;
        if (l <= treeLeft and treeRight <= r)
            return Tree[level][idx];
        int m = (treeLeft + treeRight) / 2;
        return merge(query(level + 1, 2 * idx, treeLeft, m, l, r), query(level + 1, 2 * idx + 1, m + 1, treeRight, l, r));
    }
public:
    SegmentTree(v < T > & A, T neutralValue) {
        this -> neutralValue = neutralValue;
        int n = A.size();
        Tree.push_back(v < T > (1, neutralValue));
        int prev = 1;
        while (prev < n) {
            Tree.push_back(v < T > (2 * prev, neutralValue));
            prev *= 2;
        }
        int levels = Tree.size();
        for (int i = 0; i < n; i++)
            Tree[levels - 1][i] = A[i];
        for (int i = levels - 2; i >= 0; i--)
            for (int j = 0; j < (1 << i); j++)
                Tree[i][j] = merge(Tree[i + 1][2 * j], Tree[i + 1][2 * j + 1]);
    }
    void update(int idx, T val) {
        int levels = Tree.size();
        Tree[levels - 1][idx] = val;
        idx /= 2;
        for (int i = levels - 2; i >= 0; i--, idx /= 2)
            Tree[i][idx] = merge(Tree[i + 1][2 * idx], Tree[i + 1][2 * idx + 1]);
    }
    T query(int l, int r) {
        if(l > r) return 0;
        return query(0, 0, 0, Tree.back().size() - 1, l, r);
    }
};


void solve()
{
    int n; cin >> n;
    vi a(n); cin >> a;
    v<pii> b(n); fon(i,n) b[i]={-1,i};
    // vi pid(n,-1);
    vi dp(n,1);
    map<int,int> m;
    fon(i,n)
    {
        if(m.count(a[i]))
            b[i]={m[a[i]],i};
        m[a[i]]=i;
    }
    sort(all(b));
    reverse(all(b));
    int ans=1;
    SegmentTree<int> st(dp,0);
    for(auto [l,r]:b)
    {
        if(l==-1) break;
        dp[r]=st.query(l+1,r-1)+2;
        st.update(r,dp[r]);
    }
    cout << *max_element(all(dp)) << endl;
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

