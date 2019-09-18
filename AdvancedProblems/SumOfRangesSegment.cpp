#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
/*
5
8 3 12 11 4
3
1 1 4
2 2 5
1 1 3
2 3 8
1 1 5
*/
ll a[10001];
ll tree[10001];
ll sum=0;
ll getSum(ll p,ll q)
{
    return p+q;
}
ll build(ll node,ll start,ll end)
{
    if(start==end)
    {
        tree[node]=a[start];
        return a[start];
    }
    ll mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node]=getSum(tree[2*node],tree[2*node+1]);
    return tree[node];       
}
ll getQuery(ll node,ll left,ll right,ll start,ll end)
{
    if((left>end) || (right<start) || (start>end))
    {
        return 0;
    }
    else if(start>=left && end<=right)
    {
        return tree[node];
    }
    ll mid=(start+end)/2;
    ll left_ans=getQuery(2*node,left,right,start,mid);
    ll right_ans=getQuery(2*node+1,left,right,mid+1,end);
    return (getSum(left_ans,right_ans)); 
}
ll updateVal(ll left,ll value)
{
    ll diff=value-a[left];
    return diff;
}
void getUpdate(ll node,ll left,ll value,ll start, ll end)
{
    if(left<start || left>end)
    {
        return ;
    }
    ll p=updateVal(left,value);
    tree[node]+=p;
    if(start!=end)
    {
        ll mid=(start+end)/2;
        getUpdate(2*node,left,value,start,mid);
        getUpdate(2*node+1,left,value,mid+1,end);
    }

}
int main()
{
    ll t,i,q,j,n,k,p,b,c;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        //cout<<a[i]<<" ";
    }
    build(1,1,n);
    for(i=1;i<=9;i++)
    {
        cout<<tree[i]<<" ";
    }
    //cout<<a[1]<<endl;
    cin>>q;
    while(q--)
    {
        cin>>p>>b>>c;
        if(p==1)
        {
            ll m=getQuery(1,b,c,1,n);
            cout<<m<<endl;
        }
        else
        {
            getUpdate(1,b,c,1,n);
        }
    }
}
 
