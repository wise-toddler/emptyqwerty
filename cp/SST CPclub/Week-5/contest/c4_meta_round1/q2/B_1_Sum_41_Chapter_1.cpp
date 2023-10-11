
// https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-1/problems/B1
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
vi primeFactors(int n)
{
    vi factors;
    while (n % 2 == 0)
    {
        factors.pb(2);
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factors.pb(i);
            n = n / i;
        }
    }
    if (n > 1)
    {
        factors.pb(n);
    }
    return factors;
}
void print(vi v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    cout << endl;
}
void print(vii v)
{
    for(int i=0;i<v.size();i++)
    {
        //cout << i << ' ';
        print(v[i]);
    }
}
signed main()
{
    IOS
    int t;cin >> t;
    for(int tt=1;tt<=t;tt++)
    {
        cout << "Case #" << tt << ": ";
        int n;cin >> n;
        vi a = primeFactors(n);
        int sum = 0;
        for(int i=0;i<a.size();i++) sum += a[i];
        if(sum>41)
        {
            cout << -1 << endl;
            continue;
        }
        int b = 41 - sum;
        if(b+a.size()>100)
        {
            cout << -1 << endl;
            continue;
        }
        while(b--)
        {
            a.pb(1);
        }
        cout<< a.size()<< ' ';
        print(a);
    }
}