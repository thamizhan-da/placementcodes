#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(1000006,true);
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
int x,y,p;
bool valid(int k)
{
	int curr = 0,i;
	for(i=0;i<k;i++)
	{
		if(prime[x+i])
			curr++;
	}
	if(curr<p)
		return false;
	for(i=k;i<y-x+1;i++)
	{
		if(prime[x+i-k])
			curr--;
		if(prime[x+i])
			curr++;
		if(curr<p)
			return false;
	}	 
	return true;
}
int main()
{
	sieve();
	cin>>x>>y>>p;
	int lo = 1, hi = y-x+1,mid,ans=INT_MAX;
	while(lo<=hi)
	{
		mid = lo+(hi-lo)/2;
		if(valid(mid))
		{
			ans = min(ans,mid);
			hi = mid-1;
		}
		else
			lo = mid+1;
	}
	if(ans==INT_MAX)
		cout<<-1;
	else
		cout<<ans;
}	