#include<bits/stdc++.h>
#define ll long long int
using namespace std;
/*
8 
1 2 3 4 5 6 7 8
5
1 5 8
2 5 7
1 1 7
2 2 9
1 1 8
*/
ll a[100001];
ll b_size;
ll block[1000];
void update(ll index,ll val)
{
    ll temp=index/b_size;
    //cout<<block[temp]<<endl;
    block[temp]=block[temp]-a[index]+val;
    //cout<<block[temp]<<endl;
    a[index]=val;
    //cout<<a[index]<<endl;
}
ll range(ll left, ll right)
{
    ll sum=0; 
    //cout<<b_size<<endl;
    /*for(int i=0;i<b_size;i++)
    {
        cout<<block[i]<<" ";
    }
    cout<<endl;*/
    while(left<right && left%b_size!=0)  // left side not completily overlapped 
    {
        sum+=a[left];
        left++;
    }
    while(left+b_size<=right)
    {
        sum+=block[left/b_size];
        left+=b_size;
    }
    while(left<=right)
    {
        sum+=a[left];
        left++;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q,type,l,r,n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //cout<<b_size<<endl;
    b_size=ceil((double)(sqrt(n)));
    //cout<<b_size<<endl;
    for(i=1;i<=n;i++)
    {
        block[i/b_size]+=a[i];
    }
    cin>>q;
    //cout<<block[0]<<" "<<block[1]<<" "<<block[2]<<endl;
    while(q--)
    {
        cin>>type>>l>>r;
        //cout<<type<<" "<<l<<" "<<r<<endl;
        if(type==1)
        {
            cout<<range(l,r)<<endl;
        }
        else
        {
            update(l,r);
        }
            
    }
    //a.clear();
}





