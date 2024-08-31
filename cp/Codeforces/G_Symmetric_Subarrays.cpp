// https://codeforces.com/gym/105262/problem/G
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
const int mod = 1e9+7;



class ArrayManipulator {
public:
    vi arr;
    vi brr;
    int n;

    ArrayManipulator(int size) : n(size), arr(size, 0), brr(size, 0) {}

    void processQuery(int a, int d, int l, int r) {
        if(l > r) return;
        arr[l] += (a - (d * l));
        if (r + 1 < n) arr[r + 1] -= (a - (d * l));


        brr[l] += d;
        if (r + 1 < n) brr[r + 1] -= d;
    }

    void buildPrefixSum() {
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
            arr[i] = (arr[i] + mod) % mod;
            brr[i] += brr[i - 1];
            brr[i] = (brr[i] + mod) % mod;
        }
    }
    int get(int i) {
        return (arr[i] + (brr[i] * i) % mod) % mod;
    }   
};

struct Manacher {
  vector<int> p[2];
  // p[1][i] = (max odd length palindrome centered at i) / 2 [floor division]
  // p[0][i] = same for even, it considers the right center
  // e.g. for s = "abbabba", p[1][3] = 3, p[0][2] = 2
  Manacher(vector<int> &s) {
    int n = s.size();
    p[0].resize(n + 1);
    p[1].resize(n);
    for (int z = 0; z < 2; z++) {
      for (int i = 0, l = 0, r = 0; i < n; i++) {
        int t = r - i + !z;
        if (i < r) p[z][i] = min(t, p[z][l + t]);
        int L = i - p[z][i], R = i + p[z][i] - !z;
        while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) 
          p[z][i]++, L--, R++;
        if (R > r) l = L, r = R;
      }
    }
  }
  bool is_palindrome(int l, int r) {
    int mid = (l + r + 1) / 2, len = r - l + 1;
    return 2 * p[len % 2][mid] + len % 2 >= len;
  }
};

void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    Manacher manacher(a);
    ArrayManipulator diff(n);
    for(int i = 0; i < n; ++i)
    {
        int l = i - manacher.p[1][i];
        int r = i + manacher.p[1][i];
        diff.processQuery(1, 1, l, i); // a,d,l,r
        diff.processQuery((r - l) / 2, -1, i + 1, r);
    }
    for(int i =0;i<n;i++)
    {
        int l = i - manacher.p[0][i];
        int r = i + manacher.p[0][i]-1;
        if(manacher.p[0][i] == 0) continue;
        diff.processQuery(1, 1, l, i-1); // a,d,l,r
        diff.processQuery((r - l + 1) / 2, -1, i , r);
    }
    diff.buildPrefixSum();
    int ans=0;
    for(int i = 0; i < n; i++)
    {
        int curr = (diff.get(i)*a[i])%mod;
        ans += curr;
        ans = (ans + mod)%mod;
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

