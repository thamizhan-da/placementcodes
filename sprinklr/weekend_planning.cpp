#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	vector<pll> adj[n+1];
	ll i,j,a,b,w;
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>w;
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
	}
	ll dis[n+1][k+1];
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=k;j++)
			dis[i][j]=INT_MAX;
	}
	for(i=0;i<=k;i++)
		dis[1][k]=0;
	set<pair<ll,pair<ll,ll>>> q;
	q.insert({0,{1,0}});
	while(!q.empty())
	{
		auto curr = *(q.begin());
		q.erase(q.begin());
		ll distance = curr.first;
		ll node = curr.second.first;
		ll removed = curr.second.second;
		for(auto val : adj[node])
		{
			if(dis[val.first][removed] > distance+val.second)
			{	
				q.erase({dis[val.first][removed],{val.first,removed}});
				dis[val.first][removed] = distance+val.second;
				q.insert({dis[val.first][removed],{val.first,removed}});	
			}
			if(removed<k && dis[val.first][removed+1] > distance)
			{
				q.erase({dis[val.first][removed+1],{val.first,removed+1}});
				dis[val.first][removed+1] = distance;
				q.insert({dis[val.first][removed+1],{val.first,removed+1}});	
			}
		}
	}
	vector<ll> ans(n+1,INT_MAX);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=k;j++)
			ans[i]=min(ans[i],dis[i][k]);
	}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}