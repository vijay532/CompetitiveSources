#include<bits/stdc++.h>
#define ll long long
using namespace std;
//const int N=100;
vector<ll>v;
/*
2
(((())))
(()(()))
*/
int go(ll low, ll high)
{
	if(low+1==high)
	{
		return 1;
	}
	ll mid=v[low];
	if(mid==high)
	{
		return (2*(go(mid+1,high-1)));
	}
	else
	{
		return go(low,mid)+go(mid+1,high);
	}
}
int main()
{
	ll t,i,j,n,l;
	cin>>t;
	while(t--)
	{
		stack<int>s;
		string str;
		cin>>str;
		n=str.length();
		cout<<str<<" "<<n<<endl;
		//i=0;
		v.resize(n,0);
		cout<<v[2]<<endl;
		for(i=0;i<n;i++)
		{
			if(str[i]==')')
			{
				int t=s.top();
				v[t]=i;
				s.pop();
			}
			else
			{
				s.push(i);
			}
		}
		//cout<<go(0,n-1);
}
}