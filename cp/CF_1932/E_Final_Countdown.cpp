// https://codeforces.com/contest/1932/problem/E
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
    // int n;cin >> n;
    // string s;cin >> s;
    // int a = stoll(s);
    // int ans = 0;
    // fo1(i,1,12346,1) 
    // {
    //     // ans should increase by no of different digits than that are present in i-1 
    //     string s = to_string(i);
    //     if(s.back() == '0')
    //     {
    //         int c=0;
    //         while(s.back() == '0')
    //         {
    //             c++;
    //             s.pop_back();
    //         }
    //         ans += c;
    //         // continue;   
    //     }
    //     ans++;
    //     // cout << i << ' ';
    // }
    // cout << ans << endl;
    int n;cin >> n;
    string s;cin >> s;
    int carry = 0;
    string ans="";
    int sum=0;
    for(auto ch: s)
        sum += ch-'0';
    
    fo1(i,n-1,-1,-1)
    {
        sum -= s[i]-'0';
        ans += (char)((s[i]-'0'+sum+carry)%10+'0');
        // deb(ans)
        // deb(sum)
        // deb(carry)
        // nl
        carry = (s[i]-'0'+sum+carry)/10;
    }   
    // deb(carry)
    if(carry)
        ans += (char)(carry+'0');
    reverse(all(ans));
    // remove leading zeros
    int i=0;
    while(i<ans.size() && ans[i]=='0')
        i++;
    if(i==ans.size())
        cout << 0 << endl;
    else
        cout << ans.substr(i) << endl;  

    // cout << ans << endl;


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