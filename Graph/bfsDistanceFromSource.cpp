//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
vector<ll>g[100001];
ll visit[10001];
ll dis[10001];
void bfs(ll st)
{
    queue<ll>q;
    q.push(st);
    //cout<<st<<" ";
    visit[st]=1;
    dis[st]=0;
    cout<<st<<" "<<dis[st]<<endl;
    while(!q.empty())
    {
        ll tmp=q.front();
        q.pop();
        for(auto i:g[tmp])
        {
            //cout<<i<<" ";
            if(!visit[i])
            {   
                dis[i]=dis[tmp]+1;
                q.push(i);
                visit[i]=1;
                cout<<i<<" "<<dis[i]<<endl;
            }
            else
            {
                continue;
            }
        }
    }
}
int main()
{
    ll i,j,k,n,m,u,src,v;
    cin>>n>>m>>src;
    while(m--)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(src);
}