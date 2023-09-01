#include <iostream>
#include <vector>
using namespace std;
char prob(int i)
{
    static char arr[] = {'c','o','d','e','c','h','e','f'};
    return arr[i];
}
string anagrama(vector<char>& a)
{
    for(int i =0;i<8;i++)
    {
        if(a[i]==prob(i))
        {
            bool flag=false;
            for(int j=0;j<8;j++)
            {
                if(i!=j && a[j]!=prob(i) && a[i]!=prob(j))
                {
                    flag=true;
                    int temp = a[i];
                    a[i]=a[j];
                    a[j]=temp;
                    break;
                }
            }
            if(!flag)
                return "-1";
        }
    }
    string s="";
    for(int i =0;i<8;i++)
        s+=a[i];
    return s;
}
int main() {
	// your code goes here
	int t;cin>>t;
	while(t--)
	{
	    string s;cin >> s;
	    vector<char> charvec;
	    for(char a: s)
	        charvec.push_back(a);
	    cout << anagrama( charvec )<<"\n";
	    
	}
	return 0;
}
