// #include <iostream>
// #include <vector>
// using namespace std;
// bool isIn(vector<int>& final, int q)
// {
//     int n = final.size();
//     for(int i =0;i<n;i++)
//     {
//         if(final[i]==q)
//             return false;
//     }
//     return true;
// }

// int main() 
// {
//     long n;
//     vector<int> final;
//     cin >> n;
//     while(n--)
//     {
//         int a;
//         cin >> a;
//         if(isIn(final,a))
//             final.push_back(a);
//     }
//     cout << final.size();
// }
//TLE coz n*(n+1)/2 iterations
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    long n;
    vector<int> final;
    cin >> n;
    int m=n;
    while(m--)
    {
        int a;
        cin >> a;
        final.push_back(a);
    }
    sort(final.begin(), final.end());

    int count=1;
    for(int i =0 ;i<n-1;i++)
        if(final[i]!=final[i+1])
            count++;
    cout << count << endl;
}