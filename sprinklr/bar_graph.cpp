#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,diff;
	cin>>n>>k;
	vector<int> v(n);
	int i;
	for(i=0;i<n;i++)
		cin>>v[i];
	multiset<int> s;
	int ans=INT_MAX,len=n-k;
	for(i=1;i<len;i++)
	{
		diff = v[i]-v[i-1];
		s.insert(diff);
	}
	ans = min(ans,*(s.rbegin()));
	for(i=len;i<n;i++)
	{
		diff = v[i]-v[i-1];
		s.insert(diff);
		diff = v[i-len+1]-v[i-len];
		s.erase(s.find(diff));
		ans = min(ans,*(s.rbegin()));
	}
	cout<<ans<<endl;
}