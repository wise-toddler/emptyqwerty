// https://codeforces.com/contest/1886/problem/B
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
int px,py;
int ax,ay;
int bx,by;
bool check(double w)
{
    double is0ina = pow(ax,2)+pow(ay,2)-pow(w,2) ;
    double is0inb = pow(bx,2)+pow(by,2)-pow(w,2) ;
    double ispina = pow(px-ax,2)+pow(py-ay,2)-pow(w,2) ;
    double ispinb = pow(px-bx,2)+pow(py-by,2)-pow(w,2) ;
    if(is0ina>0 && is0inb>0)
        return 0;
    if(ispina>0 && ispinb>0)
        return 0;
    if(is0ina<=0 && ispina<=0)
        return 1;
    if(is0inb<=0 && ispinb<=0)
        return 1;

    double a = sqrt(pow(bx-ax,2)+pow(by-ay,2));
    if(is0ina<=0 && ispinb<=0)
    {
        if(a<=2*w)
            return 1;
    }
    if(is0inb<=0 && ispina<=0)
    {
        if(a<=2*w)
            return 1;
    }
    return 0;
}
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        cin >> px >> py;
        cin >> ax >> ay;
        cin >> bx >> by;
        double ans=0.0;
        double st = 0,ed = 1e4;
        while(ed-st>1e-7)
        {
            double mid = st + (ed-st)/2;   
            if(check(mid))
            {
                ans = mid;
                ed = mid;
            }
            else
            {
                st = mid;
            }
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
}// logic satish cc