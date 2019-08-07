#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <map>
#include <utility>
#include <sstream>
#include <queue>

using namespace std;

#define ll long long int
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define en "\n"
#define vll vector <pll> 
#define INF 10001;

int calculateDist(int source,int destination,vector<int> cities[])
{
    //let's do the bfs
    bool visited[100005];
    int distance[100005],i,adj;
    
    for(int i = 0;i<100005;i++)
    {
        visited[i] = false;
        distance[i] = -1;
    }

    queue <int> q;

    q.push(source);
    visited[source] = true;

    distance[source] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(i=0;i<cities[cur].size();i++)
        {
            adj = cities[cur][i];

            if(!visited[adj])
            {
                distance[adj] = distance[cur] + 1;
                visited[adj] = true;
                q.push(adj);
            }
        }
    }

    return distance[destination];
}

int main() {
	// your code goes here
    int t,i,h,k,z,m,r,a,b;
	
    cin>>t;
    
	while(t--)
    {
        cin>>h>>k>>m>>z>>r;

        //0th city doesn't exist.. 
        vector<int> cities[10005];

        //connecting aint the roads
        for(i=0;i<r;i++)
        {
            cin>>a>>b;

            cities[a].push_back(b);
            cities[b].push_back(a);
        }

        //calculating Minimum Distance from Kevin to Home without medicine
        int homeNoMed = calculateDist(k,h,cities);

        //calculating Minimum Distance from Kevin to Home with medicine
        int homeMed = calculateDist(k,m,cities);
        int homeMed2 = calculateDist(m,h,cities);

        //calculating Minimum Distance from Zombie to Home 
        int homeZom = 2*calculateDist(z,h,cities);

        // printf("%intd %intd %intd %intd\n", homeMed, homeNoMed, homeMed2, homeZom);
        if(homeMed < 0 || homeMed2 < 0 || homeNoMed < 0 || homeZom < 0) {
            printf("-1\n");
        }
        else if((homeMed + homeMed2)<=homeZom)
        {
            cout<<"With"<<en;
        }
        else if(homeNoMed<=homeZom)
        {
            cout<<"Without"<<en;
        }
        else
        {
            cout<<"-1"<<en;
        }
    }
	return 0;
}
