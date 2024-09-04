// https://codeforces.com/contest/1934/problem/C
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
// add all points to a set who are at a manhattan distance of d from a point
int n,m;
void solve()
{
    cin >>n>>m;
    // fill all the points in p
    // p.clear();
    // fon(i,n) fon(j,m) p.pb({i,j});
    cout << "? " << 1 << " " << 1 << endl;
    // cout.flush();
    int d;cin >> d;
    if(d==0)
    {
        cout << "! " << 1 << " " << 1 << endl;
        return;
    }
    // pii a={0,m-1},b={n-1,0};

    pii a,b;
    if(d<min(n,m))
    {
        a={0,d};
        b={d,0};
    }
    else
    {
        if(d>=n && d>=m)
        {
            a={d-m+1,m-1};
            b={n-1,d-n+1};
        }
        else if(d>=n)
        {
            a={0,d};
            b={n-1,d-n+1};
        }
        else if (d>=m)
        {
            a={d-m+1,m-1};
            b={d,0};
        }
    }
    cout << "? " << a.first+1 << " " << a.second+1 << endl;
    int d1;cin >> d1;
    if(d1==0)
    {
        cout << "! " << a.first+1 << " " << a.second+1 << endl;
        return;
    }
    cout << "? " << b.first+1 << " " << b.second+1 << endl;
    // cout.flush();
    int d2;cin >> d2;
    if(d2==0)
    {
        cout << "! " << b.first+1 << " " << b.second+1 << endl;
        return;
    }
    if(d1&1 || d2&1)
    {
        if(d1&1) 
        {
            b = {b.first-(d2/2),b.second+(d2/2)};
            cout << "! " << b.first+1 << " " << b.second+1 << endl;
            return;
        }

        if(d2&1) 
        {
            a = {a.first+(d1/2),a.second-(d1/2)};
            cout << "! " << a.first+1 << " " << a.second+1 << endl;
            return;
        }
        // return;
    }
    else
    {
        pii ch = {b.first-(d2/2),b.second+(d2/2)};
        cout << "? " << ch.first+1 << " " << ch.second+1 << endl;
        cout.flush();
        int d3;cin >> d3;
        if(d3==0)
        {
            cout << "! " << ch.first+1 << " " << ch.second+1 << endl;
            return;
        }
        ch = {a.first+(d1/2),a.second-(d1/2)};
        cout << "! " << ch.first+1 << " " << ch.second+1 << endl;
        return;
    }
}
signed main()
{
    // IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        // a={0,0};
        solve();
    }
}