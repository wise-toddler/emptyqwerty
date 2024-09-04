// https://codeforces.com/gym/104955/problem/E
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
class mxq
{
public:
    deque<pii> q;
    void push(int x)
    {
        int cnt = 1;
        while (q.size() && q.back().first <= x)
        {
            cnt += q.back().second;
            q.pop_back();
        }
        q.push_back({x, cnt});
    }
    void pop()
    {
        if (q.front().second > 1)
        {
            q.front().second--;
            return;
        }
        q.pop_front();
    }
    int max()
    {
        return q.front().first;
    }
};
void solve()
{
    int n, x;
    cin >> n >> x;
    vvi a(n, vi(3));
    fon(j, 3)
            fon(i, n)
                cin >>
        a[i][j];
    // print a
    sort(all(a));
    // for(auto &i : a)
    //     cout << i << endl;

    int i = 0, j = 0;
    int ans = 0;
    mxq q1, q2;

    while (i < n)
    {
        while (j < n && a[j][0] <= a[i][0] + x)
        {
            q1.push(a[j][1]);
            q2.push(a[j][2]);
            j++;
        }
        ans = max(ans, q1.max() + q2.max());
        q1.pop();
        q2.pop();
        i++;
    }
    cout << ans << endl;
    // nl nl
}
signed main()
{
    IOS
        // TxtIO
        int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}