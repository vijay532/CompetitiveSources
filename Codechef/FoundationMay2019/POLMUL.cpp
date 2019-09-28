//https://www.codechef.com/FLPAST01/problems/POLMUL
//g++  5.4.0

#include <iostream>
#define ll long long 
using namespace std;
/*
3
2 2
1 -1
1 1
3 2
1 2 1
0 1
3 3
1 2 1
1 -2 1
*/
int main()
{
    ll t,i,n,j,q,ans,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ll a[n+m]={0};
        ll f[n];
        ll s[m];
        for(i=0;i<n;i++)
        {
            cin>>f[i];
        }
        for(i=0;i<m;i++)
        {
            cin>>s[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                ll k=i+j;
                a[k]+=(f[i]*s[j]);
            }
        }
        for(i=0;i<n+m-1;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}