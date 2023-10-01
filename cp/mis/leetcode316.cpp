// https: // leetcode.com/problems/remove-duplicate-letters/?envType=daily-question&envId=2023-09-26
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

string removeDuplicateLetters(string s)
{
    int n = s.size();

    stack<char> st;
    vector<int> done(26, 0);

    vector<int> left(26, 0);
    for (int i = 0; i < n; i++)
        left[s[i] - 'a']++;

    for (char a : s)
    {
        left[a - 'a']--;

        if (done[a - 'a'])
            continue;

        if (!st.size())
        {
            st.push(a);
            done[a - 'a']=1;
            continue;
        }

        if (st.top() < a)
        {
            done[a - 'a']++;
            st.push(a);
            continue;
        }
        while (true)
        {
            if (st.size() and a < st.top() and left[st.top() - 'a'] != 0)
            {
                done[st.top() - 'a']=0;
                st.pop();
            }
            else
                break;
        }

        st.push(a);
        done[a - 'a']++;
    }
    string ret = "";
    while (st.size())
    {
        ret = st.top() + ret;
        st.pop();
    }
    return ret;
}
signed main()
{
    IOS
    cout << removeDuplicateLetters("cbacdcbc") << endl;    
}