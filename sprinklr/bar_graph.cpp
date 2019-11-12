#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	deque<int> q(n);
	int i;
	for(i=0;i<n;i++)
		cin>>q[i];
	int a,b;
	// int end = n-1;
	while(k--)
	{
		int end = q.size()-1;
		a = q[1]-q[0];
		b = q[end]-q[end-1];
		if(a>b)
		{
			q.pop_front();
			// start++;
		}
		else
		{
			q.pop_back();
			// end--;
		}
		// cout<<a<<" "<<b<<" ";
		// cout<<start<<" "<<end<<endl;
	}
	int ans=0;
	for(i=1;i<q.size();i++)
		ans = max(ans,q[i]-q[i-1]);
	cout<<ans;
}