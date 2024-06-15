// 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
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
vi primes(1e5+1,1);
vector<int> pri;
void sieve()
{
    primes[0]=primes[1]=0;
    for(int i=2;i*i<=1e5;i++)
    {
        if(primes[i])
        {
            for(int j=i*i;j<=1e5;j+=i)
            {
                primes[j]=0;
            }
        }
    }
    for(int i=3;i<=1e5;i++)
    {
        if(primes[i])
        {
            pri.pb(i);
        }
    }
}


bool hasTwoSum(int target) {
    int left = 0;
    int right = pri.size() - 1;

    while (left < right) 
    {
        int total = pri[left] + pri[right];
        if (total == target) 
            return true;
        else if (total > target) 
            right--;
        else 
            left++;
        
    }
    return false;
}
bool solve()
{
    int n;cin>>n;
    n-=4;
    return hasTwoSum(n);
    // return binary_search(all(desired),n);
    // return desired.find(n-4)!=desired.end();
}
signed main()
{
    IOS
    sieve();
   cout << pri << endl;
    // fun();
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        // solve();/
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}