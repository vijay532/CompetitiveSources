//g++  5.4.0
// https://www.codechef.com/FLPAST01/problems/MAY19F1/
#include <iostream>
#define ll long long 
using namespace std;
/*
1        
5 3        
5 4 8 6 9        
2 3 5
*/
int main()
{
    ll t,i,n,j,q,ans,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        ll a[n];
        for(i=0;i<n;i++)
        {
            cin>>m;
            if(i==0)
            {
                a[i]=m;
            }
            else
            {
                a[i]=max(a[i-1],m);
            }
            //cout<<a[i]<<" ";
        }
        while(q--)
        {
            cin>>j;
            cout<<a[j-1]<<endl;
        }
    }
}