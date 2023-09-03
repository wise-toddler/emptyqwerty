#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}
int main() {
	// your code goes here
	int t;cin >> t;
	while(t--)
	{
	    int n;cin >> n;
	    int k;cin >> k;
	    int l;cin >> l;
	    vector<int> pasteries;
	    for (int i = 0; i <n; i++)
	    {
	        int a;cin >> a;
	        pasteries.push_back(a);
	    }
	    sort(pasteries.begin(), pasteries.end(), compare);
	    long long sum=0;
        for(int i=l-1;i<n;i+=k)
            sum+=pasteries[i];
        std::cout << sum << std::endl;
	}
	return 0;
}
