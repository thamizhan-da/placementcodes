ll ncr(ll n,ll r)
{
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
  return p;
}
string solve(int a, int b, int k) 
{
  int n = a+b;
  k++;
  long long sum=0,i;
  string ans(n,'*'); 
  while(a>0 && b>0 and i<n)
  {
      if(k<=sum+(ncr(a+b-1,a-1)))
      {  
        ans[i] = 'H';
        a--;
      }
      else
      {

        ans[i]= 'V';
        sum+=ncr(a+b-1,a-1);
        b--;
      }
      // cout<<a<<" "<<b<<" "<<ans[i]<<endl;
      i++;
  }
  while(a>0 and i<n)
  {
      ans[i]='H';
      i++;
      a--;
  }
  while(b>0 and i <n)
  {
      ans[i]='V';
      i++;
      b--;
  }
    // cout<<ans<<endl;
  return ans;
}
