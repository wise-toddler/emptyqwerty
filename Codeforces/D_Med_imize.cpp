// https://codeforces.com/contest/1993/problem/D
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
#include <bits/stdc++.h>
#define maxn 3000005
#define max_elem 1000000
using namespace std;

class SegmentTreeMedian {
    vector<int> segmentTree;
    
public:
    SegmentTreeMedian() {
        segmentTree.resize(maxn, 0);
    }

    void update(int node, int a, int b, int x, int diff) {
        if (a == b && a == x) {
            segmentTree[node] += diff;
            return;
        }

        if (x >= a && x <= b) {
            update(node * 2, a, (a + b) / 2, x, diff);
            update(node * 2 + 1, (a + b) / 2 + 1, b, x, diff);

            segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
        }
    }

    int findKth(int node, int a, int b, int k) {
        if (a != b) {
            if (segmentTree[node * 2] >= k)
                return findKth(node * 2, a, (a + b) / 2, k);

            return findKth(node * 2 + 1, (a + b) / 2 + 1, b, k - segmentTree[node * 2]);
        }
        return (segmentTree[node]) ? a : -1;
    }

    void insert(int x) {
        update(1, 0, max_elem, x, 1);
    }

    void remove(int x) {
        update(1, 0, max_elem, x, -1);
    }

    int median() {
        int k = (segmentTree[1] + 1) / 2;
        return findKth(1, 0, max_elem, k);
    }
};

// int main() {
//     SegmentTreeMedian stm;
//     stm.insert(1);
//     stm.insert(4);
//     stm.insert(7);
//     cout << "Median for the set {1,4,7} = " << stm.median() << endl;
//     stm.insert(8);
//     stm.insert(9);
//     cout << "Median for the set {1,4,7,8,9} = " << stm.median() << endl;
//     stm.remove(1);
//     stm.remove(8);
//     cout << "Median for the set {4,7,9} = " << stm.median() << endl;
//     return 0;
// }

void solve()
{
    SegmentTreeMedian stm;
    int n,k;cin >> n >> k;
    vi a(n);cin >> a;
    fo1(i,k,n,1) stm.insert(a[i]);
    // nl
    int ans=stm.median();
    deb(ans)
    for(int i=0;i+k<n;i++)
    {
        // deb(a[i])
        // deb(a[i+k])
        // nl
        stm.insert(a[i]);
        stm.remove(a[i+k]);
        deb(stm.median())   
        ans=max(ans,stm.median());
    }
    cout << ans << endl;
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