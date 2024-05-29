// https://codeforces.com/contest/1955/problem/E
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
// bool ch(string s,int i)
// {
//     int n=s.size();
//     // flip windows of size i and check if all 1s
//     for(int j=0;j+i<=n;j++)
//     {
//         if(s[j]=='1') continue;
//         for(int k=j;k<j+i;k++)
//         {
//             // flip window
//             if(s[k]=='0') s[k]='1';
//             else s[k]='0';
//         }
//     }
//     return count(all(s),'1')==n;
// }
bool ch(string s, int i) {
    int n = s.size();
    vector<int> diff(n + 1, 0);

    // flip windows of size i and check if all 1s
    for (int j = 0; j + i <= n; j++) {
        if(j)
        {
            diff[j] += diff[j - 1];
        }
        int curr= (s[j] == '1') ? 1 : 0;
        if((diff[j]&1 == 1)) curr = 1-curr;
        if(curr==0)
        {
            diff[j]++;
            diff[j+i]--;
        }
    }
    for(int j=n-i+1;j<n;j++)
    {
        if(j)
        {
            diff[j] += diff[j - 1];
        }
        int curr= (s[j] == '1') ? 1 : 0;
        if((diff[j]&1 == 1)) curr = 1-curr;
        if(curr==0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;cin>>n;
    string s;cin >> s;
    if(count(all(s),'1')==n)
    {
        cout << s.size() << endl;
        return;
    }

    while(s.size() && s.back()=='1') s.pop_back();
    reverse(all(s));
    while(s.size() && s.back()=='1') s.pop_back();
    // deb(s)
    
    if(count(all(s),'1')==0)
    {
        cout << s.size() << endl;
        return;
    }
    fo1(i,s.size()-1,0,-1)
    {
        if(ch(s,i))
        {
            cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;

}
signed main()
{
    IOS
    //TxtIO
    // cout << ch("00100",4) << endl;  
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}