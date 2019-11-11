#include <bits/stdc++.h>
using namespace std;

int preprocess(string s)
{
	int n = s.length(),i,j,k;
	vector<int> lps(n,0),ans(n);
	lps[0]=0;
	ans[0]=n-1;
	for(i=1;i<n;i++)
	{
		k = lps[i-1];
		while(k>0 && s[i]!=s[k])
		{
			ans[i-k] = k;
			k = lps[k-1];
		}
		if(s[i]==s[k])
			k++;
		lps[i]=k;
	}
	int sum=0;
	for(i=0;i<n;i++)
		cout<<lps[i]<<" ";
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
		sum+=ans[i];
	}	
	return sum;
}

int main()
{
	string s;
	cin>>s;
	s+="$";
	cout<<preprocess(s)<<endl;
	// string pat,text;
	// cin>>text>>pat;
	// string s = pat+'#'+text;
	// int n = s.length(),k,i;
	// vector<int> f(n,0);
	// f[0]=0;
	// std::vector<int> ans;
	// for(i=1;i<n;i++)
	// {
	// 	k = f[i-1];
	// 	while(k>0 && s[i]!=s[k])
	// 		k = f[k-1];
	// 	if(s[i]==s[k])
	// 		k++;
	// 	f[i] = k;
	// 	if(k==pat.length())
	// 	{
	// 		ans.push_back(i-2*pat.length());
	// 	}
	// }
	// for(i=0;i<ans.size();i++)
	// 	cout<<ans[i]<<" ";
}