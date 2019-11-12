#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a(100005),in(100005),out(100005),v((100005));
vector<ll> bit(100005);

ll n;
vector<ll> adj[100005];
ll timer;
void update(ll index,ll x)
{
	while(index<=timer)
	{
		bit[index]+=x;
		index += (index &(-index));
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
void dfs(ll src,ll par)
{
	in[src]=++timer;
	for(auto node : adj[src])
	{
		if(node!=par)
			dfs(node,src);
	}
	v[in[src]]=a[src];
	out[src]=timer;
}
int main()
{
	cin>>n;
	ll i,ai,b;
	for(i=1;i<=n-1;i++)
	{
		cin>>ai>>b;
		adj[ai].push_back(b);
		adj[b].push_back(ai);
	}
	for(i=1;i<=n;i++)
		cin>>a[i];
	timer=0;
	dfs(1,-1);
	for(i=1;i<=timer;i++)
		update(i,v[i]);
	ll q,t,x,ans,index;
	cin>>q;
	while(q--)
	{
		cin>>t;
		if(t==0)
		{
			cin>>index>>x;
			update(in[index],x);
		}
		else
		{
			cin>>x;
			ans = query(out[x])-query(in[x]-1);
			cout<<ans<<endl;
		}
	}
}