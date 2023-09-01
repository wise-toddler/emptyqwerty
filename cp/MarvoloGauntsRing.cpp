// #include <iostream>
#include "bits/stdc++.h"
// #include <vector>
#include <cmath>

// using namespace std;
// int main()
// {
//     long long n,p,q,r; cin >> n >> p >> q >> r;
//     vector<long long> v(n);
//     for (long long i = 0; i < n; i++)
//             cin >> v[i];
        
//     // for(long long i=0;i<n;i++)
//     //     cout << v[i] << endl;
//     long long int maxi=LLONG_MIN;
//     for(long long i=0;i<n-2;i++)
//     {
//         cout << v[i]*p+v[i+1]*q+v[i+2]*r<<endl;
//         maxi=max(maxi,v[i]*p+v[i+1]*q+v[i+2]*r);
//     }
//     // cout<<maxi;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, p, q, r;
    cin >> n >> p >> q >> r;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> maxP(n), maxQ(n), maxR(n);
    vector<long long> minP(n), minQ(n), minR(n);

    // Initialize max and min arrays
    maxP[0] = p * a[0];
    minP[0] = p * a[0];
    maxQ[0] = q * a[0];
    minQ[0] = q * a[0];
    maxR[0] = r * a[0];
    minR[0] = r * a[0];

    for (int i = 1; i < n; i++) {
        maxP[i] = max(maxP[i - 1], p * a[i]);
        minP[i] = min(minP[i - 1], p * a[i]);
        maxQ[i] = max(maxQ[i - 1], q * a[i]);
        minQ[i] = min(minQ[i - 1], q * a[i]);
        maxR[i] = max(maxR[i - 1], r * a[i]);
        minR[i] = min(minR[i - 1], r * a[i]);
    }

    long long int x = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        long long maxVal = maxP[i] + maxQ[i] + maxR[i];
        long long minVal = minP[i] + minQ[i] + minR[i];
        x = max(x, maxVal);
        x = max(x, minVal);
    }

    cout << x << endl;

    return 0;
}
