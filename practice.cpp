#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j;
	cin>>n;
	std::vector<int> a(n),dp(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		dp[i] = a[i];
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]%a[j]==0)
				dp[i] = max(dp[i],dp[j]+a[i]);
		}
	}
	int ans=0;
	for(i=0;i<n;i++)
		ans = max(ans,dp[i]);
	cout<<ans;
}