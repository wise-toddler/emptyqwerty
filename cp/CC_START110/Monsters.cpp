// https://www.codechef.com/START110B/problems/SPCP5
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
// vector<bool> isPrime(1e6+1,true);
// void genprimes(int n)
// {
//     unordered_set<int> primes;
//     isPrime[0] = isPrime[1] = false;
//     for(int i=2;i*i<=n;i++)
//         if(isPrime[i])
//             for(int j=i*i;j<=n;j+=i)
//                 isPrime[j] = false;            
    
//     // for(int i=2;i<=n;i++)
//     //     if(isPrime[i])
//     //         primes.insert(i);
//     // return primes;
// }
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0)
            return false;
    return true;
}
void solve()
{
    int n;cin >> n;
    int moves = 0;
    if(n==1)
    {
        cout << 1 << endl;
        return;
    }
    int ans =1;
    // int m = primes.size();
    int power = 1;
    while(n>0)
    {
        
        if(isPrime(n)){
            moves++;
            break;
        }
        else{
            n= n-power;
            moves++;
            power*=2;
        }
    }
    if(n<0)
    cout << -1 << endl;
    else
    cout << moves << endl;
}
signed main()
{
    // genprimes(1e6);
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}