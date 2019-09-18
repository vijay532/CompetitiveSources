#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
10 1 10 2 1
*/
ll s,g,u,d,f;
ll mark[1000001];
ll dist[1000001];
void compute()
{
    //cout<<s<<" "<<f<<" "<<g<<u<<d;
    ll current,next_up,next_down;
    queue<ll>q;
    q.push(s);
    dist[s]=0;
    mark[s]=1;
    while(!q.empty())
    {
        current=q.front();
        q.pop();
        next_up=current+u;
        next_down=current-d;
        //cout<<next_up<<" "<<next_down<<" ";
        while(next_up<=f && !mark[next_up])
        {
            mark[next_up]=1;
            q.push(next_up);
            dist[next_up]=dist[current]+1;
        }
        while(next_down>=1 && !mark[next_down])
        {
            mark[next_down]=1;
            q.push(next_down);
            dist[next_down]=dist[current]+1;
        }
        //cout<<q.size()<<endl;
    }
    return ;
}
int main()
{
    cin>>f>>s>>g>>u>>d;   
    dist[g]=-1;
    compute();
    if(dist[g]==-1)
    {
        cout<<"use the stairs";
    }
    else
    {
        cout<<dist[g];
    }
} 