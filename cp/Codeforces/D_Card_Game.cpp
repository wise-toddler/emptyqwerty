// https://codeforces.com/contest/1932/problem/D
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
void solve()
{
    int n;
    cin >> n;
    char trump;
    cin >> trump;
    map<char, set<int>> mp;
    map<char, vi> mp2;
    vector<string> cards;
    fon(i, 2 * n)
    {
        string s;
        cin >> s;
        cards.pb(s);
        mp[s[1]].insert(s[0] - '0');
        mp2[s[1]].pb(s[0] - '0');
    }
    // for(auto x : mp2)
    //     sort(all(x.second));
    // if (mp[trump].size() >= n) // case easy
    // {
    //     v<string> ans;
    //     set<int> &s = mp[trump];
    //     for (auto it = s.rbegin(); it != s.rend(); it++)
    //     {
    //         ans.pb(to_string(*it) + trump);
    //         cards.erase(find(all(cards), (to_string(*it) + trump)));
    //         if (ans.size() == n)
    //             break;
    //     }
    //     for (int i = 0; i < n; i++)
    //         cout << cards[i] << ' ' << ans[i] << endl;
        
    //     return;
    // }
    int ods = (mp['S'].size() & 1) + (mp['H'].size() & 1) + (mp['D'].size() & 1) + (mp['C'].size() & 1) - (mp[trump].size() & 1);
    if (ods > mp[trump].size())
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<string> ans;
    for (auto x : mp2)
    {
        if (x.first == trump)
            continue;
        vi s = x.second;
        sort(all(s));
        for(int i=0;i<s.size()/2*2;i+=2)
            cout << s[i] << x.first << " " << s[i+1] << x.first << endl;
        if (s.size() & 1)
        {
            int i=s.back();
            s.pop_back();
            cout << i << x.first << " " << *mp[trump].begin() << trump << endl;
            mp[trump].erase(mp[trump].begin());
        }
    }
    vi trumps(all(mp[trump]));
    for (int i = 0; i < trumps.size(); i += 2)
    {
        cout << trumps[i] << trump << ' ' << trumps[i + 1] << trump << endl;
    }
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