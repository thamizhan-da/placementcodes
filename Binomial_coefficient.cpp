#include <bits/stdc++.h>
using namespace std;
#define hell 1000000007
#define ll long long
vector<ll> fact(1000005,1),invfact(1000005,1);

ll power(ll x, ll y,ll p)
{
	ll ans=1;
	x%=p;
	while(y>0)
	{
		if(y%2)
			ans*=x;
		ans%=hell;
		x*=x;
		x%=hell;
		y/=2;
	}
	return ans;
}
ll inverse(ll x)
{
	return power(x,hell-2,hell);
}
void preprocess()
{
	ll i,j;
	for(i=2;i<=1000000;i++)
	{
		fact[i] = (i*fact[i-1]);
		fact[i] %= hell;
	}
	invfact[1000000] = inverse(fact[1000000]);
	for(i=999999;i>=1;i--)
	{
		invfact[i] = (i+1)*invfact[i+1];
		invfact[i]%=hell;
	}
}
ll ncr(int n,int r)
{
	return (((fact[n]*invfact[r])%hell)*invfact[n-r])%hell;
}
