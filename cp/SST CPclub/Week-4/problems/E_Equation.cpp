// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
// sqrt newton rapson
double squareRoot(double x)
{
    assert(x >= 0);
    double epsilon = 1e-12; 
    double guess = x / 2.0; 

    while (abs(guess * guess - x) > epsilon)
    {
        guess = 0.5 * (guess + x / guess); 
    }

    return guess;
}
signed main()
{
    IOS 
    double c;cin>>c;
    int a=25;
    double g = c; 
    while (a--)
    {
        double sqg = squareRoot(g);
        double eqn = g*g + sqg -c;
        double deqn = 2*g + (1/(2*sqg));
        g = g - (eqn/deqn);
    }
    cout << fixed << setprecision(18) << g << endl;
    
}