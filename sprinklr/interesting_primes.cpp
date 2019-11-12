#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> prime(1000005,true);
vector<ll> bit(1000005);
void update(ll index,ll x)
{
	while(index<=1000000)
	{
		bit[index]+=x;
		index += (index & (-index));
	}	
}
ll query(ll index)
{
	ll ans=0;
	while(index>0)
	{
		ans+=bit[index];
		index -= (index & (-index));
	}
	return ans;
}
void sieve()
{
	int i,j;
	prime[1]=false;
	for(i=2;i*i<=1000000;i++)
	{
		if(prime[i])
		{
			for(j=i*i;j<=1000000;j+=i)
				prime[j]=false;
		}
	}
}

void preprocess()
{
	vector<bool> flag(1000000,false);
	ll i,j,val;
	for(i=1;i*i*i*i<=1000000;i++)
	{
		for(j=1;j*j<=1000000;j++)
		{
			val = i*i*i*i+j*j;
			if(val<=1000000 && prime[val] && !flag[val])
			{
				flag[val]=true;
				update(val,1);
			}
		}
	}
}
int main()
{
	sieve();
	int t;
	cin>>t;
	ll a;
	preprocess();
	while(t--)
	{
		cin>>a;
		cout<<query(a)<<endl;
	}	
}