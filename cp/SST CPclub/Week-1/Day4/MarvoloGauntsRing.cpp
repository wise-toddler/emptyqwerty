// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-1/Day-4.md
// https://codeforces.com/problemset/problem/855/B
#include "bits/stdc++.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, p, q, r;
    cin >> n >> p >> q >> r;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];// input array

    vector<long long> ai(n); // maximum p*ai from left
    vector<long long> ak(n); // maximum r*ak from right 

    ai[0]=a[0]*p;
    ak[n-1]=a[n-1]*r;
    if(n==1) 
    {
        cout<<a[0]*(p+q+r)<<endl;
        return 0;
    }
    for (int i = 1; i < n-1; i++) // calculating ai and ak
    {
        ai[i]=max(ai[i-1],a[i]*p);
        ak[n-i-1]=max(ak[n-i],a[n-i-1]*r);
    }
    ai[n-1]=max(ai[n-2],a[n-1]*p);
    ak[0]=max(ak[1],a[0]*r);

    long long int max = LLONG_MIN;

    for (int j = 0; j < n; j++) // calculating max iteratively over every j 
    {
        long long int x = ai[j] + a[j]*q + ak[j];
        if (x > max) 
            max = x;
    }
    cout << max << endl;
    return 0;
}
/*
for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
    {
        for(int k=j;k<n;k++)
        {
            long long int x = a[i]*p + a[j]*q + a[k]*r;
            if(x>max)
                max=x;
        }
    }
}// O(n^3) solution tle confirmed
*/
/*
6 1 -1 2
-1 2 3 -4 5 -6
-1 2 3 3 5 5
10 10 10 10 10 -12
*/