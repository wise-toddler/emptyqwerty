// https://codeforces.com/contest/1990/problem/C
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
void solve()
{
    int n;cin>>n;
    vi a(n);cin>>a;
    // operation 1
    int ans=accumulate(all(a),0LL);
    int mad=0;
    // deb(a);
    map<int,int> mp;
    fon(i,n)
    {
        mp[a[i]]++;
        if(mp[a[i]]>1) mad=max(mad,a[i]);
        a[i]=mad;    
    }
    // deb(a); // op1 
    // cout << ans << endl; // op1 
    // cout << " op1 done " << ans << endl;
    mp.clear(); 
    ans+=accumulate(all(a),0LL);
    mad=0;
    fon(i,n)
    {
        mp[a[i]]++;
        if(mp[a[i]]>1) mad=max(mad,a[i]);
        a[i]=mad;    
    }
    // deb(a); // op2
    // cout << ans << endl; // op2
    // cout << " op2 done " << ans << endl;

    // after op2 all segs have length>=2 except the last one
    mp.clear();
    for(auto i:a) if(i!=0) mp[i]++; 
    // print mp
    if(mp.size()==0)
    {
        cout << ans << endl;
        return;
    }
    reverse(all(a));
    // while(a.back()==0) a.pop_back();    
    // cout << " maths " << ans << endl;
    // auto [lx,ly]=*mp.rbegin();
    // deb(lx);deb(ly);
    // int sum=accumulate(all(a),0LL)-lx*ly;
    // deb(sum);
    // for(auto [x,y]:mp) 
    // {
    //     int ac = sum*y;
    //     int nc2 = (y*(y+1)/2)*x;
    //     ans+=ac;
    //     ans+=nc2;
    //     sum-=x*y;
    // }
    // cout << ans << endl;
    // n=a.size();
    fon(i,n)
    {
        ans+=a[i]*(i+1);
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

/*
1
14
7 7 5 2 10 4 2 3 10 8  3  2  8  4 = 75
0 7 7 7 7 7 7 7 10 10 10 10 10 10 = 109
0 0 7 7 7 7 7 7 7 10 10 10 10 10 = 99 
0 0 0 7 7 7 7 7 7 7 10 10 10 10 = 89
0 0 0 0 7 7 7 7 7 7 7 10 10 10 = 79
0 0 0 0 0 7 7 7 7 7 7 7 10 10 = 69
0 0 0 0 0 0 7 7 7 7 7 7 7 10 = 59
0 0 0 0 0 0 0 7 7 7 7 7 7 7 = 49
0 0 0 0 0 0 0 0 7 7 7 7 7 7 = 42
0 0 0 0 0 0 0 0 0 7 7 7 7 7 = 35
0 0 0 0 0 0 0 0 0 0 7 7 7 7 = 28
0 0 0 0 0 0 0 0 0 0 0 7 7 7 = 21
0 0 0 0 0 0 0 0 0 0 0 0 7 7 = 14
0 0 0 0 0 0 0 0 0 0 0 0 0 7 = 7 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 

*/