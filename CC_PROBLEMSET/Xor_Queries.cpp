// https://www.codechef.com/problems/XRQRS?tab=statement
#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
class trie
{
public:
    trie *child[2];
    vector<int> idx;
    trie()
    {
        child[0] = child[1] = NULL;
        idx = vi(0);
    }
};
trie *dum = new trie();
int bits = 31;
void insert(int x)
{
    trie *cur = dum;
    int idx = cur->idx.size();
    cur->idx.pb(idx);
    fo1(i, bits, -1, -1)
    {
        int bit = (x >> i) & 1;
        if (!cur->child[bit] || cur->child[bit]->idx.size() == 0)
            cur->child[bit] = new trie();
        cur = cur->child[bit];
        cur->idx.pb(idx);
    }
}

// void erase() // call this k times for query 2
// {
//     int indextoberemoved = dum->idx.back();
//     dum->idx.pop_back();
//     trie *cur = dum;
//     fo1(i, bits, -1, -1)
//     {
//         if (cur->child[0]->idx.back() == indextoberemoved)
//         {
//             cur->child[0]->idx.pop_back();
//             cur = cur->child[0];
//         }
//         else
//         {
//             cur->child[1]->idx.pop_back();
//             cur = cur->child[1];
//         }
//         if (cur->idx.size() == 0)
//         // {
//         //     delete cur;
//         //     cur = NULL;
//             break;
//         // }
//     }
// }

void erase()
{
    int idx = dum->idx.back();
    function<void(trie *, int)> f = [&](trie *cur, int i)
    {
        if (i == -1) return;
    
        assert(cur->idx.back() == idx);
        cur->idx.pop_back();

        int b = (cur->child[1] and cur->child[1]->idx.back() == idx);

        f(cur->child[b], i - 1);
        if (cur->child[b] and cur->child[b]->idx.size() == 0)
        {
            delete cur->child[b];
            cur->child[b] = 0;
        }
    };
    f(dum, bits);
}

int isvalidLR(int l, int r, trie *cur)
{
    auto it1 = lower_bound(all(cur->idx), l);
    auto it2 = lower_bound(all(cur->idx), r+1);
    if (it1 == cur->idx.end() || it2 == cur->idx.begin())
        return 0;
    return it2-it1;
}

void query0()
{
    int x; cin >> x;
    insert(x);
}

void query1()
{ // max xor in l and r
    int l, r, x;
    cin >> l >> r >> x;
    l--, r--;
    trie *cur = dum;
    int ans = 0;
    fo1(i, bits, -1, -1)
    {
        int bit = (x >> i) & 1;
        int rb = 1 - bit;
        if (cur->child[rb] && isvalidLR(l, r, cur->child[rb]))
        {
            ans += (1 << i);
            cur = cur->child[rb];
        }
        else
            cur = cur->child[bit];
    }
    cout << (ans^x) << endl;
}

void query2()
{
    int k;
    cin >> k;
    while (k--)
        erase();
}

void query3()
{ // less than x in l and r
    int l, r, x; cin >> l >> r >> x;
    l--, r--;
    trie *cur = dum;
    int ans = 0;
    fo1(i, bits, -1, -1)
    {
        int bit = (x >> i) & 1;
        if (bit==0 && cur->child[1])
            ans += isvalidLR(l, r, cur->child[1]);
        if (!cur->child[bit])
            break;
        cur = cur->child[bit];
    }
    cout << isvalidLR(l, r, dum) - ans << endl;
}
void query4()
{// kth smallest in l and r
    int l, r, k;
    cin >> l >> r >> k;
    l--, r--;
    trie *cur = dum;
    int ans = 0;
    fo1(i, bits, -1, -1)
    {
        int bit = 1;
        if (cur->child[0] && isvalidLR(l, r, cur->child[0]) >= k)
            bit = 0;
        else if(cur->child[0])
            k -= isvalidLR(l, r, cur->child[0]);
        cur = cur->child[bit];
        ans += (1 << i) * bit;
    }
    cout << ans << endl;
}

void solve()
{
    int q;cin >> q;
    while (q--)
    {
        int t;cin >> t;
        switch (t)
        {
            case 0: query0(); break;
            case 1: query1(); break;  
            case 2: query2(); break;
            case 3: query3(); break;
            case 4: query4(); break;
        }
    }
}
signed main()
{
    IOS
    // TxtIO
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}