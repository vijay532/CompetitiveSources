//g++  5.4.0
// https://www.codechef.com/ALPAST01/problems/FASTROAD/
#include <bits/stdc++.h>
#define ll long long 
#define INF LLONG_MAX
using namespace std;
/*
1            
5 6 1 5            
1 2 7 4            
1 4 10 2            
2 3 5 2            
4 3 4 3            
3 5 2 1            
4 5 8 5       
void dijsktra(ll source)
{
    set<pair<ll,double>>s;
    vector<ll>dis(n,INF);
    s.insert(make_pair(source,0));
    dis[source]=0;
    while(!s.empty())
    {
        pair<ll,double>temp=*(s.begin());
        s.erase(s.begin());
        ll u=temp.first;
        for(auto it:g[u])
        {
            ll v=it.first;
            double length=it.second;
            //cout<<v<<" "<<length<<"ji ";
            if(dis[v]>length+dis[u])
            {
                if(dis[v]!=INF)
                {
                    s.erase(s.find(make_pair(v,dis[v])));
                }
                dis[v]=length+dis[u];
                s.insert(make_pair(v,dis[v]));
            }
        }   
    }
    cout<<dis[d]<<endl;
}*/
ll d;
vector<pair<ll,double>>g[100001];
void dij(ll source)
{
    //cout<<d<<" ";
    set< pair<double,ll> > setds;
    vector<double> dist(100001, INF);
    setds.insert(make_pair(0,source));
    dist[source] = 0;
    ll sum=0;
    while (!setds.empty())
    {
        pair<double,ll> tmp = *(setds.begin());
        setds.erase(setds.begin());
        ll u = tmp.second;
        for(auto i:g[u])
        {
            ll v= i.first;
            double weight = i.second;
            //cout<<v<<" "<<dist[v]<<" "<<dist[u]<<" "<<weight<<" "<<endl;
            if (dist[v] > dist[u] + weight)
            {
                /*if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v],v)));*/
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v],v));
                //cout<<dist[v]<<" ";
                //sum+=dist[v];
            }
            //cout<<dist[v]<<" ";
        }
        /*for(auto i:setds)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }*/
    }
    if(dist[d]!=INF)
    {
        cout<<fixed<<setprecision(8)<<dist[d]<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    //return dist[d];
}
int main()
{
    ll t,i,s,a,b,l,sp,n,m;
    cin>>t;
    while(t--)
    {
        //g.clear();
        cin>>n>>m>>s>>d;
        ll temp=m;
        for(i=0;i<100001;i++)
        {
            g[i].clear();
        }
        while(temp--)
        {
            cin>>a>>b>>l>>sp;
            double res=((l*1.0)/sp);
            //cout<<res<<" ";
            g[a].push_back(make_pair(b,res));
            g[b].push_back(make_pair(a,res));
        }
        dij(s);
        /*for(auto i:g[4])
        {
            cout<<i.first<<" "<<i.second<<" ";
        }*/
        //cout<<fixed<<setprecision(8)<<dij(s)<<endl;
        //free(g);
        
    }
}