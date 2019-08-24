//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll expo(ll n, ll k)
{
    if(k==0)
    {
        return 1;
    }
    else if(k==1)
    {
        return n;
    }
    ll res=expo(n,k/2);
    if(k%2)
    {
        return res*res*n;
    }
    else
    {
        return res*res;
    }
}
int main()
    
{
    ll l,r,i,j;
    cin>>l>>r;
    vector<ll>v;
    for(i=0;i<20;i++)  
    {
        for(j=0;j<15;j++)
        {
            v.push_back(expo(3,i)*expo+(5,j));
        }
    }
    ll count=0;
    for(i=0;i<v.size();i++)
    {
        if(l<=v[i] && v[i]<=r)
        {
            count++;
        }
    }
    cout<<count<<endl;
}
/*
Compilation time: 1.43 sec, absolute running time: 0.07 sec, cpu time: 0.01 sec, memory peak: 3 Mb, absolute service time: 1,51 sec*/