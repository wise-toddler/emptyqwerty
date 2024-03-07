// https://codedrills.io/contests/icpc-india-preliminary-2023-mock-round/problems/lcm-pairs
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}

int countPairs(vi &a)
{
    int n = a.size();
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    int count = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp[a[i]] != 0)
        {
            count += mp[a[i]]-1;
            mp[a[i]]--;
        }
        else
        {
            int this_count = 0;
            for (int j = a[i]; j <= a[n - 1]; j += a[i])
            {
                this_count += freq[j];
                if (j == a[i])
                    this_count--;
            }
            count += this_count;
            mp[a[i]] = this_count;
        }
        // cout << count << endl;
    }
    return count;
}

void solve()
{
    int n; cin >> n;
    vi a(n); cin >> a;
    sort(all(a));
    cout << countPairs(a) << endl;
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