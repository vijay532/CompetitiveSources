//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[100001];
ll tree[1000001];
ll getmx(ll a,ll b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
ll build(ll node, ll start, ll end)
{
    if(start==end)
    {
       tree[node]=a[start]; 
       return tree[node];
    }
    ll mid=(start+end)/2;
    tree[node]=getmx(build(2*node+1,start,mid),build(2*node+2,mid+1,end));
    return tree[node];
}
ll query(ll node, ll start,ll end,ll l,ll r)
{
    if(end<l || start>r)
    {
        return 0;
    }
    if(l<=start && end<=r)
    {
        return tree[node];
    }
    ll mid=(start+end)/2;
    query(2*node+1,start,mid,l,r);
    query(2*node+2,mid+1,end,l,r);
    tree[node]=max(tree[2*node+1],tree[2*node+2]);  
    return tree[node];
}
void update(ll node,ll start,ll end,ll idx,ll val)
{
    if(start==end)
    {
        //a[idx-1]=val;
        tree[node]=val;
        return ;
    }
    else
    {   
        ll mid=(start+end)/2;
        if(idx<=start && end<=idx)
        {
            
            update(2*node+1,start,mid,idx,val);
        }
        else
        {
            update(2*node+2,mid+1,end,idx,val);
        }
        tree[node]=max(tree[2*node+1],tree[2*node+2]);  
        return ;
    }
}
int main()
{
    ll i,j,k,n,idx,type,val,l,r,q;
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        //cout<<a[i]<<" ";
    }
    build(0,0,n-1);
    /*for(i=0;i<2*n-1;i++)
    {
        cout<<tree[i]<<" ";
    }*/
    while(q--)
    {
        cin>>type;
        if(type==1)  //updates
        {
            cin>>idx>>val;
            a[idx-1]=val;
            update(0,0,n-1,idx,val);
            
        }
        else //query
        {
            cin>>l>>r;
            cout<<query(0,0,n-1,l-1,r-1)<<endl;
        }
    }
}