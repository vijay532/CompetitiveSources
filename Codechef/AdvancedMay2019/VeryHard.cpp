//g++  5.4.0
// https://www.codechef.com/ALPAST01/problems/VERYHARD/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[10000000];
ll k;
ll tree[5][10000001];
void build(ll tree[],ll node,ll start,ll end,ll m)
{
    if(start>end)
    {
        return;
    }
    if(start==end)
    {
        tree[node]=a[start]%k==m?1:0;
        return;
    }
    ll mid=(start+end)/2;
    build(tree,2*node+1,start,mid,m);
    build(tree,2*node+2,mid+1,end,m);
    tree[node]=tree[2*node+1]+tree[2*node+2];
    return;
}
void update(ll node, ll start, ll end, ll idx, ll p, ll tree[])
{
    if(start==end)
    {
        //ll p=a[l-1]%k!=j?0:1;
        tree[node]+=p;
        return;
    }
    ll mid=(start+end)/2;
    if(idx<=mid)
    {
        update(2*node+1,start,mid,idx,p,tree);
    }
    else
    {
        update(2*node+2,mid+1,end,idx,p,tree);
    }
    tree[node]=tree[2*node+1]+tree[2*node+2];
    return;
}
ll query(ll node, ll start, ll end,ll left, ll right,ll tree[])
{
    if(start>right || end<left)
    {
        return 0;
    }
    if(start>=left && end<=right)
    {
        return tree[node];
    }
    ll mid=(start+end)/2;
    return (query(2*node+1,start,mid,left,right,tree)+query(2*node+2,mid+1,end,left,right,tree));
}
/*
5 3 5
5 4 3 2 1
2 1 5 3
1 5 9
2 1 5 0*/
int main()
{
    ll t,i,n,j,q,type,l,r,rem,val;
    cin>>n>>q>>k;
    //ll temp[n];
    //tree[k][4*n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        //a[i]=(temp[i]%k)!=m?0:1;
    }
    for(i=0;i<k;i++)
    {
        //cout<<tree[i+]<<" ";
        build(tree[i],0,0,n-1,i);
    }
    /*for(j=0;j<k;j++)
    {
        for(i=0;i<2*n-1;i++)
        {
            cout<<tree[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<"ji"<<endl;*/
    while(q--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>l>>val;
            if(a[l-1]%k==(a[l-1]+val)%k)
            {
                a[l-1]+=val;
            }
            else
            {
                update(0,0,n-1,l-1,-1,tree[a[l-1]%k]);
                a[l-1]+=val;
                update(0,0,n-1,l-1,1,tree[a[l-1]%k]);
            }
            /*for(j=0;j<k;j++)
            {
                for(i=0;i<2*n-1;i++)
                {
                    cout<<tree[j][i]<<" ";
                }
                cout<<endl;
            }*/
        }
        else
        {
            cin>>l>>r>>rem;
           cout<<query(0,0,n-1,l-1,r-1,tree[rem])<<endl;
        }
    }
    
}