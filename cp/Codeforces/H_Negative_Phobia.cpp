// https://codeforces.com/gym/517983/problem/H
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
class trie
{
public:
    v<trie *> child;
    int cnt=0;
    trie()
    {
        child.resize(2,NULL);
    }
};
trie *root=new trie();
int great(int x) // -1e14 <= x <= 1e14
{
    trie *cur = root;
    // cnt no of elements greater than x
    int k = x+1e14;
    int ans = 0;
    for(int i=63;i>=0;i--)
    {
        int b = (k>>i)&1;
        if(b==0 && cur->child[b^1])
            ans += cur->child[b^1]->cnt; 
        if(!cur->child[b])
            break;
        cur = cur->child[b];
    }
    return ans;
}
void insert(int x) // -1e14 <= x <= 1e14
{
    trie *cur = root;
    x+=1e14; // offset to make it positive 
    for (int i = 63; i >= 0; i--)
    {
        int b = (x >> i) & 1;
        if (!cur->child[b])
            cur->child[b] = new trie();
        cur = cur->child[b];
        cur->cnt++;
    }
}
int f(vi& arr) 
{
    int n = arr.size(); 
    int pss= 0;
    int ans = 0;
    insert(0);
    for(int i=0;i<n;i++)
    {
        pss += arr[i];
        ans += great(pss);
        insert(pss);
    }
    return ans;    
}
void solve()
{
    int n; cin >> n;
    root = new trie();
    vi a(n); cin >> a;
    int res = n*(n+1)/2;
    int ans = f(a); // cnt no of subarrays with sum less than 0
    cout << res - ans << endl;
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
