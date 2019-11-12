#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,right,left,next;
	cin>>n;
	vector<int> loc(n+1),range(n+1,0);
	for(i=1;i<=n;i++)
		cin>>loc[i];
	for(i=1;i<=n;i++)
	{
		left = max(0,i-loc[i]);
		right = min(n,i+loc[i]);
		range[left] = max(right,range[left]);
	}
	next = 0, right=range[1],count=0;
	for(i=1;i<=n;i++)
	{
		next = max(next,range[i]);
		if(i==right)
		{
			count++;
			right = next;
		}
	}
	cout<<count<<endl;
}