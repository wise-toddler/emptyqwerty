// https://codeforces.com/contest/1992/problem/E
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
v<pii> count_valid_pairs(int n) 
{
    v<pii> ans;
    string n_str = to_string(n);
    int n_int = n;
    int len_n = n_str.size();
    
    int count = 0;

    for (int a = 1; a <= 10000; ++a) {
        int correct_result = n_int * a;
        int s_len = len_n * a;
        int max_b = min({s_len, 10000LL});
        int st = max(1LL, (int)(s_len - to_string(correct_result).size()));

        for (int b = st; b <= max_b; ++b) {
            int remaining_len = s_len - b;
            int num_repeats = remaining_len / len_n;
            int remainder = remaining_len % len_n;
            string s="";
            for (int i = 0; i < num_repeats; ++i) {
                s += n_str;
            }
            // cout << s << endl;
            s += n_str.substr(0, remainder);
            // deb(s)
            if(s.size()>10) continue;
            if(s.size()==0) continue;
            if (stoll(s) == (correct_result-b)) {
                // count++;/
                // cout << a << ' ' << b << endl;
                ans.pb({a,b});
            }
        }
    }

    return ans;
}
void solve()
{
    int n;cin >> n;
    v<pii> ans = count_valid_pairs(n);
    cout << ans.size() << endl;
    for(auto i:ans) cout << i.ff << ' ' << i.ss << endl;

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