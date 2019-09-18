//g++  5.4.0

#include <iostream>
#define ll long long 
using namespace std;
/*
5 9 8 4
15 27 24 12
5 27 8 12 
*/
int main()
{
    ll t,i,n,j,k;
    cin>>n>>k;
    ll a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll sum=0;
    for(i=0;i<n;i++)
    {
        a[i]=a[i]*k;
        sum+=a[i];
    }   
    ll inc=a[0];
    ll exc=0;
    for(i=1;i<n;i++)
    {
        ll ex_new=inc>exc?inc:exc; // 5  9  13  
        inc=a[i]+exc; //9  13  13 
        exc=ex_new;  // 5  9   13
    }
    ll m=(inc>exc?inc:exc);
    //cout<<m<<" ";
    cout<<m+((sum-m)/k);
}
