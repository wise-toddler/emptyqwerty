// https://www.hackerrank.com/challenges/crush/problem
// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-2/Set-1.md
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define endl '\n'


/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */
// void print(vector<long> v)
// {
//     for(int i=0;i<v.size();i++)
//         cout << v[i] << ' ';
//     cout << endl;
// }
// void print(vector<vector<int>> v)
// {
//     for(int i=0;i<v.size();i++)
//     {
//         cout << i << ' ';
//         print(v[i]);
//     }
// }
long arrayManipulation(int n, vector<vector<int>> queries) 
{
    vector<long> v(n,0);
    long m=queries.size();

    for(long i=0;i<m;i++)
    {
        long l = queries[i][0];
        long r = queries[i][1];
        long k = queries[i][2];
        v[l-1] += k;
        if(r!=n)
            v[r] -=k;
    }    
    //prefix sum
    for(long i = 1; i<n;i++)
        v[i]=v[i-1]+v[i];            
    long max=INT_MIN;
    
    for (long i=0; i<n; i++) 
        if(max<v[i])
            max=v[i];
    return max;
}

int main()
{
    long n,m;cin >> n >> m;
    vector<vector<int>> v(m,vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    cout << arrayManipulation(n,v) << endl;
}