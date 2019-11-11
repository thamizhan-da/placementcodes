#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll n,r;
	cin>>n>>r;
	if(n==0 || r==0 || n==r)
		return 1;
	r = min(n-r,r);
	ll p=1,k=1;
	while(r)
	{
		p*=n;
		k*=r;
		ll g = __gcd(p,k);
		p/=g;
		k/=g;
		n--;
		r--;
	}
	cout<<p<<endl;
	return 0;
}