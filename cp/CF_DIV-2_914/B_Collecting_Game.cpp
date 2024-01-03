// https://codeforces.com/contest/1904/problem/B
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
int binarySearch(vi &arr, int target)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid; // Found the element, return its index
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Element not found
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vi sortedArr = arr;
    sort(all(sortedArr));

    vi prefixSum(n);
    prefixSum[0] = sortedArr[0];

    for (int i = 1; i < n; ++i)
    {
        prefixSum[i] = prefixSum[i - 1] + sortedArr[i];
    }

    vi check(n);

    for (int i = n - 2; i >= 0; --i)
    {
        if (prefixSum[i] >= sortedArr[i + 1])
        {
            check[i] = check[i + 1] + 1;
        }
    }

    for (int i : arr)
    {
        int index = binarySearch(sortedArr, i);
        cout << check[index] + index << ' ';
    }

    cout << endl;
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

// int binS(int x,vi &a)
// {
//     if (x<a[0]) return 0;
//     int l=0,r=a.size()-1;
//     int ans=0;
//     while(l<=r)
//     {
//         int mid = (l+r)/2;
//         if(a[mid]<=x)
//         {
//             ans=mid;
//             l=mid+1;
//         }
//         else
//             r=mid-1;
//     }
//     return ans+1;
// }
// void solve()
// {
//     int n;cin >> n;
//     vi a(n);cin >> a;
//     vi c=a;
//     sort(all(c));  
//     vi ps=c;
//     fo1(i,1,n,1)
//         ps[i]+=ps[i-1];
//     vector<pii> b(n);
//     sort(all(c));
//     vi ans(n);
//     // cout << "a: " << a << endl;
//     // cout << "c: " << c << endl;
//     // cout << "ps: " << ps << endl;
//     fo1(i,0,n,1)
//     {
//         // find the last index of a[i] in c;
//         int idx = binS(a[i],c);
//         // deb(idx);
//         // find the indeex where ps[idx] should be inserted in c to maintain sorted order;
//         int idx2 = binS(ps[idx-1],c);
//         // deb(idx2);
//         ans[i]=idx2-1;
//     }
//     cout << ans << endl;

// }