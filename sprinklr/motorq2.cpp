#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n = s.length(),start,end,curr,prev=0,i;
	int limit = min(26,(int)s.length());
	vector<int> ans(26);
	while(limit)
	{
		map<char,int> m;
		start=0,end=0,curr=0;
		while(end<n)
		{
			m[s[end]]++;
			while(start<=end && m.size()==limit)
			{
				curr++;
				m[s[start]]--;
				if(m[s[start]]==0)
					m.erase(s[start]);
				start++;
			}
			end++;
			
		}	
		ans[limit-1]=curr;
		ans[limit-1]+=prev;
		cout<<curr<<" "<<prev<<endl;
		prev+=curr;
		limit--;
	}
	for(i=0;i<26;i++)
	{
		cout<<ans[i]<<" ";
	}
}