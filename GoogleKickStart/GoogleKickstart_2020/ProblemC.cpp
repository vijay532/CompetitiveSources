#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,k;
ll a[100001];
bool chk(ll j)
{
	ll sum=0;
	//cout<<j<<" ";
	for(ll i=0;i<n-1;i++)
	{
		sum+=(a[i+1]-a[i]-1)/j;
	}
	if(sum<=k)
	{
		return 1;
	}
	return 0;
}
ll bin_src(ll str,ll end)
{
	while(str<end)
	{
		ll mid=(str+end)/2;
		if(chk(mid))
		{
			end=mid;
		}
		else
		{
			str=mid+1;
		}
	}
	return str;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll t,tt,i,ans;
	cin>>t;
	for(tt=1;tt<=t;tt++)
	{
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ans=bin_src(1,1e9);
		cout<<"Case #"<<tt<<":"<<ans<<endl;
	}

}