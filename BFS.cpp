
/////////connectivity problem ///////////////
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
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
*/
const int N=1e+5;
vector<ll>g[N];
bool visit[N];
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
    queue<ll>qu;
    visit[a]=1;
    qu.push(a);
    while(!qu.empty())
    {
        ll p=qu.front();
        qu.pop();
        cout<<p<<" ";
        for(int i:g[p])
        {
            //cout<<"ji"<<endl;
            if(!visit[i])
            {
                visit[i]=1;
                qu.push(i);
            }
            else
            {
                continue;
            }
        }
    }
    //bfs(a);
    /*for(int i:visit[10])
    {
        cout<<i<<endl;
    }*/
    //cout<<s.end()-s.begin()<<endl;
}
