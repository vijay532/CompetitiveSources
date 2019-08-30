//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
3
4 3
3 1 9 100
1 3 9 100
1 4
6 2
5 5 1 2 3 4
5 5
7 7 1 7 7
*/
int main()
{
    ll t,m,i,n,j,l;
    cin>>t;
    for(l=1;l<=t;l++)
    {
        cin>>n>>m;
        ll a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        ll sum=0;
        for(i=0;i<m-1;i++)
        {
            sum+=a[i];
        }
        //cout<<sum<<" ";
        ll ans=1000000000000;
        j=0;
        for(i=m-1;i<n;i++)
        {
            ll total=m*a[i];
            sum+=a[i];
            //cout<<total-sum<<" ";
            ans=min(ans,total-sum);
            sum-=a[j];
            //cout<<sum<<" ";
            j++;
        }
        //cout<<endl;
        cout<<"Case #"<<l<<": "<<ans<<endl;
    }
}