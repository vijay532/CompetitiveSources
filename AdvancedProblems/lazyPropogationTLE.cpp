//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
3 5
8 2 3 4 5
1 2 4
2 4 7
1 1 5
*/
ll a[100001];
ll tree[20001];
ll mark[1000001];
ll lazy[200001];
void sieve()
{
    ll i,j,n=1000000;
    for(i=2;i<=n;i++)
    {
        if(mark[i])
        {
            //prime.push_back(i);
            for(j=i*i;j<=n;j+=i)
            {
                mark[j]=0;
            }
        }
    }
    /*for(i=0;i<prime.size();i++)
    {
        cout<<prime[i]<<" ";
    }*/
}
void build(ll node,ll start,ll end)
{
    if(start==end)
    {
        //cout<<mark[]<<" ";
        tree[node]=mark[a[start]];
        //cout<<a[start]<<" "<<tree[node]<<" ";
        return;
    }
    ll mid=(start+end)/2;
    build(2*node+1,start,mid);
    build(2*node+2,mid+1,end);
    tree[node]=tree[2*node+1]+tree[2*node+2];
    return;
}
void compute(ll idx,ll l ,ll r)
{
    tree[idx]=mark[lazy[idx]]*(r-l+1);
    if(l!=r)
    {
        lazy[2*idx+1]=lazy[2*idx+2]=lazy[idx];
    }
    lazy[idx]=0;
}
void update(ll node, ll start,ll end,ll left,ll right,ll val)
{
    if(lazy[node]!=0)
    {
        compute(node,start,end);
    }
    if(start>right || end<left)
    {
        return ;
    }
    if(left<=start && end<=right)
    {
        lazy[node]=val;
        compute(node,start,end);
        return ;
        //tree[node]=val;
    }
    ll mid=(start+end)/2;
    update(2*node+1,start,mid,left,right,val);
    update(2*node+2,mid+1,end,left,right,val);
    tree[node]=tree[2*node+1]+tree[2*node+2];
    //return tree[node];
}
ll query(ll node,ll start,ll end,ll left,ll right)
{
    if(lazy[node]!=0)
    {
        compute(node,start,end);
    }
    if(start>right || end<left)
    {
        return 0;
    }
    if(left<=start && end<=right)
    {
        
        return tree[node];
    }
    ll mid=(start+end)/2;
    ll p=query(2*node+1,start,mid,left,right);
    ll q=query(2*node+2,mid+1,end,left,right);
    return p+q;
}
int main()
{
    ll t,q,i,n,j,k,type,idx,val,l,r;
    for(i=0;i<1000001;i++)
    {
        mark[i]=1;
    }
    sieve();
    cin>>t;
    while(t--)
    {
        
        cin>>n>>q;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<100001;i++)
        {
            tree[i]=0;
            lazy[i]=0;
        }
        build(0,0,n-1);
        /*for(i=0;i<2*n-1;i++)
        {
            cout<<lazy[i]<<" "; 
        }*/
        
        while(q--)
        {
            cin>>type;
            if(type==0)
            {
                cin>>l>>r>>val;
                //cout<<"ji "<<endl;
                update(0,0,n-1,l-1,r-1,val);
                
            }
            else
            {
                cin>>l>>r;
                cout<<query(0,0,n-1,l-1,r-1)<<endl;
            }
        }
    }
}