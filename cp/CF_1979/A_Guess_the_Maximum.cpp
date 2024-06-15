// https://codeforces.com/contest/1979/problem/A
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

class MaxQueue {
private:
    queue<int> q;
    deque<int> d;

public:
    void push(int x) {
        while (!d.empty() && d.back() < x) {
            d.pop_back();
        }
        d.push_back(x);
        q.push(x);
    }

    void pop() {
        if (!q.empty()) {
            if (q.front() == d.front()) {
                d.pop_front();
            }
            q.pop();
        }
    }

    int max() {
        if (!d.empty()) {
            return d.front();
        }
        return -1; // or throw an exception
    }
};
void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    MaxQueue q;
    int mn=INT_MAX;
    q.push(a[0]);
    fo1(i,1,n,1)
    {
        q.push(a[i]);
        mn=min(mn,q.max());
        q.pop();
    }
    cout << (mn-1) << endl;
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
}