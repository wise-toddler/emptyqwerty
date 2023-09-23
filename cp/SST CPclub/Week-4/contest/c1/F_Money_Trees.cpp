// https://codeforces.com/contest/1873/problem/D
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
// signed main()
// {
//     IOS
//     int t;cin >> t;
//     while(t--)
//     {
//         int n,k;cin >> n >> k;
//         vi a(n);
//         for(int i=0;i<n;i++) cin >> a[i];
//         vi b(n);
//         for(int i=0;i<n;i++) cin >> b[i];

//         int totalfruits = 0;
//         int l=0,r=0;
//         int anslength = -1;
//         while(r<n)
//         {
//             totalfruits+=a[r];
//             while(l<r and (totalfruits>k or (r>0 and b[r-1]%b[r]!=0)))
//             {
//                 totalfruits-=a[l];
//                 l++;
//             }
//             if(totalfruits<=k)
//             {
//                 anslength = max(anslength,r-l+1);
//             }

//             r++;
//         }
//         cout << max(0LL,anslength) << endl;
             
//     }
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int n, k;
int a[N + 5], h[N + 5], pref[N + 5], length[N + 5];

bool get(int dist)
{
    bool found = false;
    for (int i = 0; i < n - dist + 1; i++)
    {
        if (length[i] < dist)
        {
            continue;
        }
        int sum = pref[i + dist] - pref[i];
        if (sum <= k)
        {
            found = true;
            break;
        }
    }
    return found;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        pref[0] = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pref[i + 1] = pref[i] + a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        length[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (h[i] % h[i + 1] == 0)
            {
                length[i] = length[i + 1] + 1;
            }
            else
            {
                length[i] = 1;
            }
        }
        int l = 1, r = N;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (get(mid))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << r << endl;
    }
}