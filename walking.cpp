#include <bits/stdc++.h>
using namespace std;

int cache[1000][1000];
int n,x,y;
string s;
set<string> se;
int solve(int index,int curr,string str)
{
	if(index>=s.length())
	{
		if(curr==y)
		{
			if(se.find(str)==se.end())
			{
				se.insert(str);
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	if(cache[index][curr]!=-1) return cache[index][curr];

	int ans=0;
	if(s[index]=='l')
	{
		if(curr!=0)
		{
			string t=str+'l';

			if(se.find(t)==se.end()) {
				ans+= solve(index+1,curr-1,t);
				se.insert(t);
			}
		}
	}
	else
	{
		if(curr!=n)
		{
			string t=str+'r';
			if(se.find(t)==se.end())  { 
				ans += solve(index+1,curr+1,t);
				se.insert(t);
			}
		}
	}	
	{ans += solve(index+1,curr,str);se.insert(str);}
	return cache[index][curr]=ans;
}

int main()
{
	memset(cache,-1,sizeof(cache));
	cin>>n>>x>>y;
	cin>>s;
	string str="";
	cout<<solve(0,x,str)<<endl;
	// cout<<se.size();
}