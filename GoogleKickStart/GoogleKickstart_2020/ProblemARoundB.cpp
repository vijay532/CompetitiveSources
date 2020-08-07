#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
    ll t,tt,i,n;
    cin>>t;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    for(tt=1;tt<=t;tt++)
    {
        cin>>n;
        ll a[n],cnt=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=1;i<n-1;i++)
        {
            if(a[i]>a[i-1] && a[i]>a[i+1])
            {
                cnt++;
            }
        }
        cout<<"Case #"<<tt<<": "<<cnt<<endl;
    }   
    
}