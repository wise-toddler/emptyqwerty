// https://codeforces.com/contest/1955/problem/C
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
void solve()
{
    int n,k;cin>>n>>k;
    vi a(n);cin >> a;
    bool forl=1;
    int i=0,j=n-1;
    // if(k<=
    while(k>0 && i<j)
    {
        if(forl)
        {
            if(a[i]<=a[j])
            {
                if(k>=a[i]*2-1)
                {
                    k-= a[i]+a[i]-1;
                    a[j]-=a[i]-1;
                    a[i]=0;
                    forl=0;
                    if(a[j]==0)
                    {
                        j--;
                    }
                    i++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(k>=a[j]*2)
                {
                    k-= a[j]+a[j];
                    a[i]-=a[j];
                    a[j]=0;
                    forl=1; 
                    j--;
                    if(a[i]==0)
                    {
                        i++;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if(a[i]<a[j])
            {
                if(k>=a[i]*2)
                {
                    k-= a[i]+a[i];
                    a[j]-=a[i];
                    a[i]=0;
                    forl=0;
                    if(a[j]==0)
                    {
                        j--;
                    }   
                    i++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(k>=a[j]*2-1)
                {
                    k-= a[j]+a[j]-1;
                    a[i]-=a[j]-1;
                    a[j]=0;
                    forl=1;
                    if(a[i]==0)
                    {
                        i++;
                    }
                    j--;
                }
                else
                {
                    break;
                }
            }
        }
        // forl=!forl;
        // deb(k)  
        // cout << a << endl;
    }
    if(i==j && k>=a[i])
    {
        a[i]=0;
        cout << n << endl;
        return;
    }
    // deb(i)deb(j) 
    // deb(k) deb(forl)
    int front = i;
    int back = n-j-1;
    // deb(front)deb(back)
    int totalsinked = front+back;
    cout << totalsinked << endl;
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