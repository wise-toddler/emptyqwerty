// https://codeforces.com/gym/105262/problem/D
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
int toBaseN(int num, int base){
    int ans=0;
    while(num){
        // ans.pb(num % base);
        ans+=((num%base)==4);
        num /= base;
    }
    return ans;
}
 
void solve()
{
    int n; cin >> n;
    int st = 2;
    int en = min(n,(int)1e6);
    int curr = 0;
    int ans = -1;
 
    for(int i = st; i <= en; i++)
    {
        int cnt4 = toBaseN(n, i);
        if(curr <= cnt4){
            curr = cnt4;
            ans = i;
        }
    }
    if(curr == 0 && n >= 1e6){
        ans = n - 4;
        curr=1;
    }
    if(curr<=2 and n>=1e6 && n%4==0)
    {
        ans=n/4-1;    
    }
    cout << (curr == 0 ? -1 : ans) << endl;
 
}
 
// void solve()
// {
//     int n;cin >> n;
//     int st=2,en=min(n,(int)1e6);
//     // count 4s in string 
//     int ans=0;
//     int cnt=0;
//     if(n>100) cnt=1,ans=n-4;
//     // string ss;
//     vi as;
//     for(int i=st;i<=en;i++)
//     {
//         // string s=ninbaseb(n,i);
//         // cout << n << " " << i << " && " << convertToBase(n,i) << endl;
//         vi s=convertToBase(n,i);
//         int aa=count(s.begin(),s.end(),4);
//         if(cnt<=aa)
//         {
//             cnt=aa;
//             ans=i;
//             // ss=s;
//             as=s;
//         }
//     }
//     // deb(ss);
//     // deb(as);
//     // if(cnt==0)
//     cout << ans << endl;


// }
int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 1;
    int size = binary.size();
    
    for (int i = size - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    
    return decimal;
}
signed main()
{
    IOS
    //TxtIO
    int t=0;
    cin >> t;
    // cout << ninbaseb(320,69) << endl;
    // cout << ninbaseb(44444,10000) << endl;
    // cout << convertToBase(624,12) << endl;
    // cout << convertToBase(795,5) << endl;
    // cout << binaryToDecimal("1011010110110");
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}

// bit to decimanl code
