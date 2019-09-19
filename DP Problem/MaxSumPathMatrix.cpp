#include <bits/stdc++.h>
#define ll long long 
ll n,m,ans;
const int N=1000;
int a[N][N];
using namespace std;
/*
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16*/
int go(int i, int j)
{
	//ll ans=0;
	if(i==n-1 && j==m-1)
	{
		return a[i][j];
	}
	if(i<n-1 && j<m-1)
	{
		ans=a[i][j]+max(go(i+1,j),go(i,j+1));
	}
	else if(i==n-1)
	{
		ans=a[i][j]+go(i,j+1);
	}
	else if(j==m-1)
	{
		ans=a[i][j]+go(i+1,j);
	}
	//cout<<ans<<endl;
	return ans;
}
int main() 
{
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<a[i][j];
		}
	}*/
	cout<<go(0,0)<<endl;
	// your code goes here
	return 0;
}