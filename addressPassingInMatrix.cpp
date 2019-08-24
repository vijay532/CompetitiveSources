//g++  5.4.0

#include <iostream>
#define ll long long 
using namespace std;
ll m;
void fnct(ll a[])
{
    for(int i=0;i<m;i++) //increment at the address 
    {
        a[i]++;
    }
}
int main()
{
    ll i,n,j;
    cin>>n>>m;
    ll a[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {   
        cout<<a[i]<<" "; //address of the element 
        fnct(a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}