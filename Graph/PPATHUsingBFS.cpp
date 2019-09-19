/*
https://www.spoj.com/problems/PPATH/
*/

#include<bits/stdc++.h>
#define ll long long 
using namespace std;
vector<ll>v(10001);
ll k;
vector<ll>g[10001];
vector<ll>visit(10001,0);
ll bfs(ll n,ll m);
void sieve()
{
    int i,j;
    bool prime[9999];
    //vector<ll>:: iterator it;
    for(i=2;i<=9999;i++)
    {
        prime[i]=true;
    }
    for(i=2;i*i<=9999;i++)
    {
        if(prime[i]==true)
        {
            for(j=i*i;j<=9999;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    //it=v.begin()+1000;
    for(i=1000;i<=9999;i++)
    {
        //cout<<prime[i]<<" "<<i<<endl;
        if(prime[i])
        {
            v[k]=i;
            k++;
            //cout<<"ji"<<endl;
        }
    }
    //cout<<k;
    /*for(i=0;i<k;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;*/
}
bool getDiff(ll num1,ll num2)
{
    string n=to_string(num1);
    string m=to_string(num2);
    ll count=0;
    if(n[0]!=m[0])
    {
        count++;
    }
    if(n[1]!=m[1])
    {
        count++;
    }
    if(n[2]!=m[2])
    {
        count++;
    }
    if(n[3]!=m[3])
    {
        count++;
    }
    return (count!=1?false:true);
}
ll operation(int n,int m)
{
    sieve();
    ll i,j;
    for(i=0;i<k-1;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(getDiff(v[i],v[j]))
            {
                //cout<<i<<" "<<j<<endl;
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    ll ind1,ind2;
    for(i=0;i<k;i++)
    {
        if(v[i]==n)
        {
            ind1=i;
        }
        if(v[i]==m)
        {
            ind2=i;
        }
    }
    return(bfs(ind1,ind2));
}
ll bfs(ll a,ll b)
{
    queue<ll>q;
    visit[a]=1;
    q.push(a);
    while(!q.empty())
    {
        ll x=q.front();
        q.pop();
        for(auto i: g[x])
        {
            if(!visit[i])
            {
                visit[i]=visit[x]+1;
                q.push(i);
            }
            if(i==b)
            {
                return (visit[i]-1);
            }
        }
    }
}	
/*
3
1033 8179
1373 8017
1033 1033
*/
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    ll n,i,t,j,l,a,b;
    cin>>t;
    //sieve();
    //operation();
    while(t--)
    {
        cin>>a>>b;
        //cout<<ind1<<" "<<ind2<<endl;
        ll res=operation(a,b);
        cout<<res<<endl;
    }
}
