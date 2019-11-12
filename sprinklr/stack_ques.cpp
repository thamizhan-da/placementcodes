#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int n,k;
	cin>>n>>k;
	cin>>s;
	int i;
	stack<pair<char,int>> st;
	for(i=0;i<n;i++)
	{
		if(!st.empty() && st.top().first==s[i])
		{
			if(st.top().second==k-1)
			{
				while(!st.empty() && st.top().first==s[i])
					st.pop();
			}
			else
				st.push({s[i],st.top().second+1});
		}
		else
			st.push({s[i],1});
	}
	string ans;
	while(!st.empty())
	{
		ans.push_back(st.top().first);
		st.pop();
	}
	reverse(s.begin(),s.end());
	cout<<ans;
	return 0;
}