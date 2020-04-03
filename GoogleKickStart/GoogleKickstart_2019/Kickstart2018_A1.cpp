//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
4
42
11
1
2018
*/
bool is_even(ll n)
{
    return (n&1?false:true);
}
bool all_even(ll n)
{
    while(n)
    {
        ll rem=n%10;
        n/=10;
        if(!is_even(rem))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ll t,k,n,r,i,c;
    k=0;
    cin>>t;
    while(t--)
    {
        k++;
        cin>>n;
        ll p=n;
        ll q=n;
        ll ci=0;
        ll cd=0;
        if(!all_even(n))
        {
            //cout<<"ji"<<endl;
            ci=0;
            while(!all_even(p--))
            {
                //p--;
                cd++;
                //cout<<p<<endl;
            }
            while(!all_even(q++))
            {
                //q++;
                ci++;
            }
            cout<<"Case #"<<k<<": "<<min(ci,cd)<<endl;
        }
        else
        {
            cout<<"Case #"<<k<<": "<<min(ci,cd)<<endl;
        }
        //cout<<"Case #"<<k<<": "<<p.first<<" "<<p.second<<endl;
    }
}