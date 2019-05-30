
/////////dfs roblem ///////////////
#include <iostream>
#include <vector>
#include <map>
#include <set>
#define ll long long 
using namespace std;
/*
6 5
1 2
2 3
3 4
4 5
5 2
2
2 6
1 5
*/
const int N=1e+5;
vector<ll>g[N];
bool visit[N];
void dfs(int u)
{
    visit[u]=1;
    cout<<u<<" ";
    for(int i:g[u])
    {
        if(visit[i])
        {
            continue;
            //dfs(i);
        }
        dfs(i);
    }
}
int main() 
{
    ll i,n,q,m,v,u,a,b;
    cin>>n>>m;
    while(m--)
    {
        cin>>v>>u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    cin>>a;
    dfs(a);
    /*for(int i:visit[10])
    {
        cout<<i<<endl;
    }*/
    //cout<<s.end()-s.begin()<<endl;
}
