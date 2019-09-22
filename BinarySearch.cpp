//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[100001];
bool bs(ll start,ll end,ll s)
{
    while(start<=end)
    {
        ll mid=(start+end)/2;
        if(a[mid]==s)
        {
            return true;
        }
        else if(a[mid]<s)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return false;
}
int main()
{
    ll n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    cin>>search;
    cout<<bs(0,n-1,search)<<" ";
}