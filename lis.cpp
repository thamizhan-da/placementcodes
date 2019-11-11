#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int i,j;
	vector<int> dp(n+1,INT_MAX),a(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	dp[0]=INT_MIN;
	for(i=0;i<n;i++)
	{
		j = upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
		if(dp[j-1]+k<=a[i] && a[i]+k<=dp[j])
			dp[j]=a[i];
	}
	int ans;
	for(i=0;i<n;i++)
		if(dp[i]!=INT_MAX)
			ans = i;
	cout<<ans;	
}