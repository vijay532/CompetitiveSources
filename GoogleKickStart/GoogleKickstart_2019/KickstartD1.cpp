//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
2
4 3
10 21 3 7
1 13
0 32
2 22
5 1
14 1 15 20 26
4 26
*/
ll setBits(ll n)
{
    if(n==0)
    {
          return 0;
    }
    else
    {
        return(1+setBits(n&(n-1)));
    }
}
int main()
{
    ll t,q,k,n,r,i,c,idx,val,j;
    k=0;
    cin>>t;
    while(t--)
    {
        k++;
        cout<<"Case #"<<k<<": ";
        cin>>n>>q;
        ll a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        while(q--)
        {
            cin>>idx>>val;
            a[idx]=val;
            ll ans=0;
            for(i=0;i<n;i++)
            {
                ll x=a[i];
                for(j=i+1;j<n;j++)
                {
                    ll res=x^a[j];
                    x=res;
                    if(setBits(res)%2==0)
                    { 
                        ans=max(ans,j-i+1);
                    }
                }
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}