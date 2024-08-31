// https: // www.codechef.com/START102D/problems/BITPLAY
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
string s;
int m=1000000007LL;
int good(int i)
{
    int x = (((s[i - 2] - '0') ^ (s[i - 1] - '0')) == (s[i] - '0'));
    x+= (((s[i - 2] - '0') & (s[i - 1] - '0')) == (s[i] - '0'));
    x+= (((s[i - 2] - '0') | (s[i - 1] - '0')) == (s[i] - '0'));
    return x;
}
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int n;cin>>n;
        cin>>s;
        int c=1;
        bool f=0;
        for(int i=2;i<n;i+=2)
        {
            // cout<< s[i-2] <<' '<< s[i-1] <<' '<< s[i] <<endl;
            // cout << (((s[i - 2] - '0') ^ (s[i - 1] - '0')) == (s[i] - '0')) << ' ' << (((s[i - 2] - '0') & (s[i - 1] - '0')) == (s[i] - '0')) << ' ' << (((s[i - 2] - '0') | (s[i - 1] - '0')) == (s[i] - '0')) << endl;
            cout<< good(i) <<endl;  
            c=(c%m*good(i)%m)%m;
        }
        cout<< (c%m) <<endl<<endl;
    }
}