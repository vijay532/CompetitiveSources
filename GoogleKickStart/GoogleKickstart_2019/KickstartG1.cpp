//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
3
11 1 2
8
2 3
11 11 11
1 2 3 4 5 6 7 8 9 10 11
1 2 3 4 5 6 7 8 9 10 11
1000 6 1
4 8 15 16 23 42
1
*/
ll cnt[100001];
ll tmp[100001];
int main()
{
    ll t,i,n,j,x,k,m,tornPage;
    cin>>t;
    for(x=1;x<=t;x++)
    {
        cin>>n>>m>>k;
        vector<ll>v;   // max size 100000
        vector<ll>ans;
        ll mx=0;
        for(i=1;i<=100001;i++)
        {
            cnt[i]=0;
            tmp[i]=0;
            //cout<<i<<" ";
        }
        for(i=0;i<m;i++)
        {
            cin>>j;
            cnt[j]++;
            //v.push_back(j);
            if(j>mx)
            {
                mx=j;
            }
            //cout<<cnt[j]<<" ";
        }
        
        for(i=1;i<=mx;i++)
        {
            for(j=i;j<=mx;j+=i)
            {
                tmp[i]+=cnt[j];
            }
        }
        /*for(i=1;i<=11;i++)
        {
            cout<<tmp[i]<<" ";
        }
        cout<<endl;*/
        for(i=1;i<=n;i++)
        {
            ll res=n/i;
            res-=tmp[i];
            ans.push_back(res);
        }
        ll sum=0;
        for(i=0;i<k;i++)
        {
            cin>>j;
            sum+=ans[j-1];
        }
        cout<<"Case #"<<x<<": "<<sum<<endl;
    }
}