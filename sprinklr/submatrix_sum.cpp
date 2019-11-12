// Find the count of all the submatrices of a matrix of size mxn, 
// such that the sum of the elements of the submatrices is divisible by given number P.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n,ll p)
{
	map<ll,ll> m;
	m[0]=1;
	ll i;
	ll sum=0,rem,ans=0;
	for(i=0;i<n;i++)
	{
		sum+=a[i];
		rem = ((sum%p)+p)%p;
		ans += m[rem];
		m[rem]++;
	}
	return ans;
}
int main()
{
	ll n,m,p;
	cin>>n>>m>>p;
	ll a[n][m];
	ll i,j,k,ans=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>a[i][j];
	ll temp[n];
	for(i=0;i<m;i++)
	{
		memset(temp,0,sizeof(temp));
		for(j=i;j<m;j++)
		{
			for(k=0;k<n;k++)
				temp[k]+=a[k][j];
			ans += solve(temp,n,p);
		}
	}
	cout<<ans;
}