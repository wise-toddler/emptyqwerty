// https://codeforces.com/contest/1941/problem/C    
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}

void solve()
{
    int n;cin >> n;
    string s;cin >> s;
    int c = 0;
    fon(i,n-2)
    {
        if(i<n-5 && s[i]=='m' && s[i+1]=='a' && s[i+2]=='p' && s[i+3]=='i' && s[i+4]=='e')
            c++,i+=4;
        else if(s[i]=='m' && s[i+1]=='a' && s[i+2]=='p')
            c++,i+=2;
        else if(s[i]=='p' && s[i+1]=='i' && s[i+2]=='e')
            c++,i+=2;
        // deb(i) deb(c) 
    }
    cout << c << endl;

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
