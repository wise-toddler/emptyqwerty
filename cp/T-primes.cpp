#include <iostream>
#include <cmath>
using namespace std;
// int sqrt(long n)
// {
//     int st=1,en=n;
//     while(st<=en)
//     {
//         int mid=st+(en-st)/2;
//         if(mid*mid==n)
//             return mid;
//         if(mid*mid <n)
//             st=mid+1;
//         else
//             en=mid-1;
//     }
//     return -1;
// }
// hasenge log agar log n mei kara ye simple sa question

// bool integerSquareRoot(int x) {
//     if (x < 0) 
//         return -1; 

//     int guess = x / 2; 

//     while (guess * guess > x)
//         guess = (guess + x / guess) / 2; 

//     return guess*guess == x;
// }
// mc logic h mera pata nhi kyun fail kar jaa rha h 

// bool isSquare(long long n) 
// {
//     int sqrt_n = sqrt(n);
//     return sqrt_n * sqrt_n == n;
// }
// // i am ashamed of using this 

double squareRoot(double n) 
{
    double accuracy = 1e-2; 
    double ans = n / 2.0;
    while (abs(ans * ans - n) > accuracy) 
        ans = 0.5 * (ans + n / ans); 
    return ans;
}

bool isPrime(long long n)
{
    if(n==2 || n==3) return true;
    if(n==4 || n<=1 || n%2==0 || n%3==0) return false;

    for(int i=5;i*i<=n;i+=6)
        if(n%i==0 || n%(i+2)==0)
            return false;
    
    return true;
}

int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        long long sqrt = squareRoot(n);
        if(sqrt*sqrt == n and isPrime(sqrt))
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}
