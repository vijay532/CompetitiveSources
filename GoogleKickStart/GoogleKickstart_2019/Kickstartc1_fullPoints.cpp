//g++  5.4.0
// pairing concept 
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
3
5 3 6 2 3
EEWNS
4 3 3 1 1
SESE
11 5 8 3 4
NEESSWWNESE
*/
map<pair<ll,ll>,pair<ll,ll>>north,east,west,south;
pair<ll,ll> fn(pair<ll,ll>p)
{
    if(north.find(p)==north.end())
    {
        return p;
    }
    else
    {
        north[p]=fn(north[p]);
        return north[p];
    }
}
pair<ll,ll> fw(pair<ll,ll>p)
{
    if(west.find(p)==west.end())
    {
        return p;
    }
    else
    {
        west[p]=fw(west[p]);
        return west[p];
    }
}
pair<ll,ll> fs(pair<ll,ll>p)
{
    if(south.find(p)==south.end())
    {
        return p;
    }
    else
    {
       south[p]=fs(south[p]);
       return south[p];
    }
}
pair<ll,ll> fe(pair<ll,ll>p)
{
    if(east.find(p)==east.end())
    {
        return p;
    }
    else
    {
        east[p]=fe(east[p]);
        return east[p];
    }
}
int main()
{
    ll t,k,n,r,i,c;
    k=0;
    cin>>t;
    while(t--)
    {
        k++;
        pair<ll,ll>p;
        cin>>n>>r>>c>>p.first>>p.second;
        string s;
        cin>>s;
        //cout<<s<<endl;
        north.clear(),west.clear(),east.clear(),south.clear();
        //cout<<p<<endl;
        north[p]=make_pair(p.first-1,p.second);
        west[p]=make_pair(p.first,p.second-1);
        south[p]=make_pair(p.first+1,p.second);
        east[p]=make_pair(p.first,p.second+1);
        /*for(auto i:west)
        {
            cout<<i.first.first<<" "<<i.first.second<<" "<<i.second.first<<" "<<i.second.second<<endl;
        }*/
        for(i=0;i<n;i++)
        {
            if(s[i]=='W')
            {
                //cout<<p.first<<" ji "<<p.second<<endl;
                p=fw(p);
                //cout<<p.first<<" "<<p.second<<endl;
                
            }
            else if(s[i]=='S')
            {
               p=fs(p); 
               //cout<<p.first<<" "<<p.second<<endl;
            }
            else if(s[i]=='E')
            {
                p=fe(p);
                //cout<<p.first<<" "<<p.second<<endl;
            }
            else
            {
                p=fn(p);
                //cout<<p.first<<" "<<p.second<<endl;
            }
            north[p]=make_pair(p.first-1,p.second);
            west[p]=make_pair(p.first,p.second-1);
            south[p]=make_pair(p.first+1,p.second);
            east[p]=make_pair(p.first,p.second+1);
        }
        cout<<"Case #"<<k<<": "<<p.first<<" "<<p.second<<endl;
    }
}