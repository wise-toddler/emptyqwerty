// https://codeforces.com/contest/126/problem/B
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
// STRING HASHING
const int p1=31;
const int m=1e9+9;
const int p2=37;
const int m2=1e9+7;
vi p_pow1;
vi p_pow2;
vi h1;
vi h2;
void init(string s)
{
    int n=s.size();
    p_pow1.resize(n);
    p_pow2.resize(n);
    h1.resize(n);
    h2.resize(n);
    p_pow1[0]=1;
    p_pow2[0]=1;
    h1[0]=(s[0]-'a'+1);
    h2[0]=(s[0]-'a'+1);
    fo1(i,1,n,1)
    {
        p_pow1[i]=(p_pow1[i-1]*p1)%m;
        p_pow2[i]=(p_pow2[i-1]*p2)%m2;
        h1[i]=(h1[i-1]+(s[i]-'a'+1)*p_pow1[i])%m;
        h2[i]=(h2[i-1]+(s[i]-'a'+1)*p_pow2[i])%m2;
    }
}
pii get_hash(int l,int r)
{
    int hash1=(h1[r]-(l==0?0:h1[l-1])+m)%m;
    int hash2=(h2[r]-(l==0?0:h2[l-1])+m2)%m2;
    hash1=(hash1*p_pow1[p_pow1.size()-1-l])%m;
    hash2=(hash2*p_pow2[p_pow2.size()-1-l])%m2;
    return {hash1,hash2};
}
bool check(int l,int r,int l1,int r1)
{
    if(r-l!=r1-l1) return false;
    return get_hash(l,r)==get_hash(l1,r1);
}
void solve()
{
    string s;cin >> s;
    int n=s.size();
    init(s);
    string aa=s.substr(1,n-2);
    // cout << aa << endl;
    // a same 
    for(int i=2,j=n-3;i<n;i++,j--)
    {
        if(check(0,j,i,n-1))
        {
            string c=s.substr(0,j+1);

            // find c in aa using hashing just loop through all the possible lengths of c
            // cout << c << endl;
            for(int l1=1,r1=j+1;r1<n-1;l1++,r1++)
            {
                if(check(l1,r1,0,j))
                {
                    cout << c << endl;
                    return;
                }
            }
        }
    }
    cout << "Just a legend" << endl;
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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}