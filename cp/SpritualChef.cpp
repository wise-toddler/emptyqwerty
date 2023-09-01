#include <iostream>
using namespace std;
long m;

long long binpow(long long a, long long b) 
{
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return ((res * res)%m * (a%m))%m;
    else
        return (res * res)%m;
}
long long int sum(long long k,long long n)
{
    if(n==1)
        return 1;

    if(n%2==1)
        return (binpow(k,n-1) + sum(k,n-1))%m;
    
    return (sum((k*k)%m,n/2)*(1+k))%m;
        
}


int main() 
{
	// your code goes here
	int t;cin>> t;
    while(t--)
    {
        long long n,k;
        cin >>n>>k>>m;
        // long long kn=binpow(k,n,m);
        long long x =sum(k,n);
        long long y = binpow(k,n)%m;
        
        cout << x<<" "<< y<< "\n";
        // cout << ((pow(k,n)-1)/(k-1))%m << " " << pow(k,n)%m;  
    }
	
	return 0;
}
