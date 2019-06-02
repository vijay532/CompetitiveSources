#include<bits/stdc++.h>
#define ll long long 
#define INF 0x3f3f3f3f
using namespace std;
//const int N=100;
vector<pair<ll,ll>>g;
ll n,m;
/*
1
5 4
1 2 3
2 3 8
3 4 10
2 4 4
2
*/
void dijkstra(int s)
{
    set<pair<ll,ll>>sd;
    set<pair<ll,ll>>:: iterator it1;
    vector<ll>dis(n,INF);
    sd.insert(make_pair(s,0)); //source and weight (2,0)
    dis[s]=0;
    while(!sd.empty())
    {
        pair<ll,ll>res=*(sd.begin());
        sd.erase(sd.begin());
        int u=res.first;  // getting the node to traverse the graph 
        list<pair<ll,ll>>:: iterator it;
        for(it=g[u].begin();it!=g[u].end();it++)
        {
            int v=(*it).first;  // 3  4 
            int weight=(*it).second;  // 8  4 
            if(dis[v]>dis[u]+weight)  // INF>0+8   INF>0+
             {
                if(dis[v]!=INF)
                {
                    sd.erase(sd.find(make_pair(v,dis[v])));
                }
                dis[v]=dis[u]+weight; //8 
                sd.insert(make_pair(v,dis[v])); // 3 8
            }
        }
        cout<<"distance"<<s<<"from"<<endl;
        for(it1=sd.begin();it1!=s.end();it1++)
        {
            cout<<"vertex"<<it.first<<"is"<<it.second<<endl;
        }
    }
}
int main()
{
    ll t,i,j,k,a,b,w;
    cin>>t;
    while(t--)
    {
        cin>>n>>m; // nodes and edges
        for(i=0;i<m;i++)
        {
            cin>>a>>b>>w;
            g[a].push_back(make_pair(b,w));
            g[b].push_back(make_pair(a,w));
        }
		int s;
        cin>>s; // source
        dijkstra(s);
        
        
    }
}