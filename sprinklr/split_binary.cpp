#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n = s.length(),count=0;
	for(auto c : s)
	{
		if(c=='1')
			count++;
	}
	if(count%3)
	{
		cout<<-1;
		return 0;
	}
	int curr=0,start,i,end;
	for(i=n-1;i>=0;i--)
	{
		if(s[i]=='1')
			curr++;
		if(curr==count/3)
		{
			end = i;
			break;
		}
	}
	string t = s.substr(end); 
	i = 0;
	while(i<n && s[i]=='0')
		i++;
	start = i;
	i = 0;
	while(i<t.length())
	{
		if(s[start+i]!=t[i])
		{
			cout<<-1;
			return 0;
		}
		i++;
	}
	start = start+t.length();
	i = start;
	while(s[i]=='0')
		i++;
	start = i;
	i = 0;
	while(i<t.length())
	{
		if(s[start+i]!=t[i])
		{
			cout<<-1;
			return 0;
		}
		i++;
	}
	i = t.length()-1;
	int ans = 0,prod=1;
	while(i>=0)
	{
		if(t[i]=='1')
			ans+=prod;
		prod*=2;
		i--;
	}
	cout<<ans;
}