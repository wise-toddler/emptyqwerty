// https://www.codechef.com/problems/KEEPOUT 
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
#include<utility>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

signed main()
{
	IOS
	// your code goes here
	int t;cin >> t;
	while(t--)
	{
		int n,m;cin >>n>>m;
		int max=m;
		set<int> s;
		s.insert(0);
		
		set<pii> p;
		p.insert(make_pair(m,0));
	    
		for(int i=0;i<n;i++)
        {
            int q;cin >>q;
			auto it = s.upper_bound(q);
			if(it == s.end())
			{
				// cout << "b";
				it--;
				pii x = make_pair(m-*it,*it);
				p.erase(x);
				p.insert(make_pair(m-q,q));
				p.insert(make_pair(q-*it,*it));
			}
			else
			{
				// cout << "a";
				int x1 = *it;
				int y1 = *(--it);
				pii x = make_pair(x1-y1,y1);
				// cout <<" "<< x.first << " " << x.second << endl;
				p.erase(x);
				p.insert(make_pair(x1-q,q));
				p.insert(make_pair(q-y1,y1));
			}		
			s.insert(q);
			cout << p.rbegin()->first << " ";
        }
		cout << endl;    
	   
	}
	return 0;
}
//ask dhruv Sir
