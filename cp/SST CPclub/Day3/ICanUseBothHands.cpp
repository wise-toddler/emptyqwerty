// https://www.codechef.com/problems/AMBIDEXTROUS
#include <iostream>

using namespace std;

int main() {
	// your code goes here
	int t;cin >> t;
	while(t--)
	{
	    int l;cin >> l;
	    int r;cin >> r;
	    int m;cin >> m;
	    if((m/l)*l==m)
	        cout << m/l +m/r << endl;
	    else
	        cout << m/l+1+m/r << endl;
	}
	return 0;
}
