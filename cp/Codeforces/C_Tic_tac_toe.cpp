// https://codeforces.com/contest/3/problem/C
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
void solve()
{
    v<v<char>> a(3,v<char>(3)); cin >> a;
    int xcnt=0,ocnt=0;
    fon(i,3)fon(j,3)
    {
        if(a[i][j]=='X') xcnt++;
        else if(a[i][j]=='0') ocnt++;
    }
    if(xcnt<ocnt || xcnt>ocnt+1)
    {
        cout << "illegal";
        return;
    }
    vvi rcnt(3,vi(2)); // row -> 0:X 1:0 
    vvi ccnt(3,vi(2)); 
    vvi dcnt(2,vi(2));
    fon(i,3)fon(j,3)
    {
        if(a[i][j]=='X') rcnt[i][0]++,ccnt[j][0]++;
        else if(a[i][j]=='0') rcnt[i][1]++,ccnt[j][1]++;
    }
    fon(i,3)
    {
        if(a[i][i]=='X') dcnt[0][0]++;
        else if(a[i][i]=='0') dcnt[0][1]++;
        if(a[i][2-i]=='X') dcnt[1][0]++;
        else if(a[i][2-i]=='0') dcnt[1][1]++;
    }
    int xwins = 0, owins = 0;
    fon(i,3)
    {
        xwins += rcnt[i][0]==3;
        xwins += ccnt[i][0]==3;
        owins += rcnt[i][1]==3;
        owins += ccnt[i][1]==3;
    }
    fon(i,2)
    {
        xwins += dcnt[i][0]==3;
        owins += dcnt[i][1]==3;
    }
    if(xwins && owins)
    {
        cout << "illegal";
        return;
    }
    if(xwins)
    {
        if(xcnt-ocnt==1)
        {
            cout << "the first player won";
            return;
        }
        cout << "illegal";
        return;
    }
    if(owins)
    {
        if(xcnt==ocnt)
        {
            cout << "the second player won";
            return;
        }
        cout << "illegal";
        return;
    }
    if(xcnt+ocnt==9)
    {
        cout << "draw";
        return;
    }
    cout << (xcnt==ocnt?"first":"second");
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
    }
}