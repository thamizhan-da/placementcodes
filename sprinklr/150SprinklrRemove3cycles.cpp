#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define F first
#define S second
#define loop(i,m,n) for(i=m;i<n;i++)
using namespace std;
const int no=1e5+10;

int n,m;
vector<int> al[no];
vector<int> vis(no,0);
int no_of_cyc=0;
vector<int> cc[no],par(no,-1),rs(no,0);
int ct=0;

void dfs(int u)
{
    vis[u]=1;
    cc[ct].push_back(u);
    rs[u]=1;
    for(int v: al[u]) 
    {
        
        if(!vis[v] ) 
        {
            par[v]=u; 
            dfs(v);
        }
        else if(v!=par[u] and rs[v]==1)  
            ++no_of_cyc;

    }
    rs[u]=0;
}

int main(){

    int a,b;
    int i=0,j=0;
    cin>>n>>m;
    if(m<=3)
    {
        cout<<n; 
        return 0;
    }
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    for(int u=1;u<=n;u++) 
        if(!vis[u]) 
        {
            dfs(u); 
            ct++;
        }
    ll ans=0;
    vector<int> arr;
    for(i=0;i<ct;i++) 
        arr.push_back(cc[i].size());
    if(no_of_cyc<3) 
    {    
        while(no_of_cyc!=3)
        {
            int id=min_element(arr.begin(),arr.end())-arr.begin();
            arr[id]--;
            if(arr[id]==0) 
                arr[id]=INT_MAX;
            ++no_of_cyc;
       }
    }
    for(i=0;i<ct;i++)
    {
        if(arr[i]!=INT_MAX) 
            ans+=arr[i]*arr[i];
    }
    cout<<ans<<endl;
    

    return 0;
}