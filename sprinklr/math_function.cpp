#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll x,ll y,ll p)
{
	ll ans=1;
	x%=p;
	while(y>0)
	{
		if(y%2)
			ans*=x;
		ans%=p;
		x*=x;
		x%=p;
		y/=2;
	}
	return ans;
}

int main()
{
	ll n,m,a,b,c;
	cin>>n>>m>>a>>b>>c;
	ll ans=1;
	if(n>=m)
	{
		cout<<0;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		ans*=power(i,i,m);
		ans%=m;
	}
	cout<<ans;
}	