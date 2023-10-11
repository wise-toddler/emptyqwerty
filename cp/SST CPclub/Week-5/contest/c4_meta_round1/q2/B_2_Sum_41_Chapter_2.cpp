// // https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-1/problems/B2
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define vi vector<int>
// #define vii vector<vector<int>>
// #define pb push_back
// #define pii pair<int, int>
// #define all(x) x.begin(), x.end()
// vi primeFactors(int n)
// {
//     vi factors;
//     while (n % 2 == 0)
//     {
//         factors.pb(2);
//         n = n / 2;
//     }
//     for (int i = 3; i * i <= n; i += 2)
//     {
//         while (n % i == 0)
//         {
//             factors.pb(i);
//             n = n / i;
//         }
//     }
//     if (n > 1)
//         factors.pb(n);
//     return factors;
// }
// signed main()
// {
//     ifstream in("input.txt");   // Open input file
//     ofstream out("output.txt"); // Open output file
//     int t;
//     in >> t;
//     for (int tt = 1; tt <= t; tt++)
//     {
//         out << "Case #" << tt << ": ";
//         int n;
//         in >> n;
//         vi a = primeFactors(n);
//         int sum = 0;
//         for (int i = 0; i < a.size(); i++)
//             sum += a[i];
//         if (sum > 41)
//         {
//             out << -1 << endl;
//             continue;
//         }
//         int b = 41 - sum;
//         if (b + a.size() > 100)
//         {
//             out << -1 << endl;
//             continue;
//         }
//         while (b--)
//         {
//             a.pb(1);
//         }
//         out << a.size() << ' ';
//         for (int i : a)
//             out << i << ' ';
//         out << endl;
//     }
//     in.close();
//     out.close();
// }

// https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-1/problems/B1
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
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
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}
signed main()
{
    IOS int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        vi a = primeFactors(n);
        int sum = 0;
        for (int i = 0; i < a.size(); i++)
            sum += a[i];
        if (sum > 41)
        {
            cout << -1 << endl;
            continue;
        }
        int r = a[0];
        vi v=a;
        int size = a.size()-1;
        // cout << sum << endl;
        // print(a);
        while(41 >= sum - r -v[size]+ v[size]*r)
        {
            v.erase(v.begin());
            v.erase(v.end()-1);
            v.pb(a[size]*r);
            size--;
            a = v;
            // cout << "&&&" << endl;
        }
        // print(a);
        sum = 0;    
        for (int i = 0; i < a.size(); i++)
            sum += a[i];
        int b = 41 - sum;
        // cout << b << endl;
        if (b + a.size() > 100)
        {
            cout << -1 << endl;
            continue;
        }
        while (b--)
        {
            a.pb(1);
        }
        cout << a.size() << ' ';
        print(a);
    }
}