// https://codeforces.com/gym/104759/problem/G
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
const int maxn=1e5+5;
// primes till 1e5
vi primes;
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
}
void solve()
{
    int n;cin>>n;
    vi a(n);
    fo1(i,0,n,1)cin>>a[i];
    int anss =0;
    sort(all(a));
    // convert it into a unordered map freq
    unordered_map<int,int> freq;
    for(int i:a)freq[i]++;

    fo1(i,0,n,1)
    {
        int ai=a[i];
        fo1(j,0,primes.size(),1)
        {
            int pj=primes[j];
            if(pj*ai>a[n-1])break;
            if(freq[pj*ai]>0)
            {
                anss+=freq[pj*ai];
            }
        }
    }
    cout << anss << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    SieveOfEratosthenes(1e5);

    while(t--)
    {
        solve();
    }
}