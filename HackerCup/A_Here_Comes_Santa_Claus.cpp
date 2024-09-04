// // https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-1/problems/A
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
signed main()
{
    IOS
    int t;cin >> t;
    for(int tt=1;tt<=t;tt++)
    {
        cout << "Case #" << tt << ": ";
        int n;cin >> n;
        vi a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(all(a));
        if(n==5)
        {
            double ans = (a[4]+a[3])/2.0 - (a[2]+a[0])/2.0;
            ans = max(ans,(a[4]+a[2])/2.0 - (a[1]+a[0])/2.0);
            cout<< fixed << setprecision(7) << ans << endl;
            continue;
        }
        double ans = (a[n-1]+a[n-2])/2.0 - (a[0]+a[1])/2.0;
        cout<< fixed << setprecision(7) << ans << endl;

    }
}
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl '\n'
// #define vi vector<int>
// #define all(x) x.begin(), x.end()

// signed main()
// {
//     ifstream in("input.txt");   // Open input file
//     ofstream out("output.txt"); // Open output file
//     int t;
//     in >> t; // Read the number of test cases from input.txt

//     for (int tt = 1; tt <= t; tt++)
//     {
//         out << "Case #" << tt << ": ";
//         int n;
//         in >> n; // Read n from input.txt
//         vi a(n);

//         for (int i = 0; i < n; i++)
//         {
//             in >> a[i]; // Read array elements from input.txt
//         }

//         sort(all(a));

//         if (n == 5)
//         {
//             double ans = (a[4] + a[3]) / 2.0 - (a[2] + a[0]) / 2.0;
//             ans = max(ans, (a[4] + a[2]) / 2.0 - (a[1] + a[0]) / 2.0);
//             out << fixed << setprecision(7) << ans << endl;
//         }
//         else
//         {
//             double ans = (a[n - 1] + a[n - 2]) / 2.0 - (a[0] + a[1]) / 2.0;
//             out << fixed << setprecision(7) << ans << endl;
//         }
//     }

//     in.close();  // Close input file
//     out.close(); // Close output file

//     return 0;
// }




// (bool) ? (true) : (false)