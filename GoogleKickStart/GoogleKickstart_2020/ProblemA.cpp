/*https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56*/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
3
4 100
20 90 40 90
4 50
30 30 10 10
3 300
999 999 999
*/
int main()
{
    ll t,i,b,n,j,k,l;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>n>>b;
        ll a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        k=0;
        ll sum=0;
        for(i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum<=b)
            {
                k++;
            }
        }
        cout<<"Case #"<<j<<": "<<k<<endl;
    }
}
