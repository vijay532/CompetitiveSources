//https://www.codechef.com/FLPAST01/problems/RADGEE

//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
3
5 4
1 4 7 10 12
3 6 4 8 22
7 8 9 14
1 2
1
5
2 5
5 2
1 2 3 4 5
10 9 8 7 6
12 11
*/
int main()
{
    ll t,i,n,j,k,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        /*ll r[n];
        ll g[n];
        for(i=0;i<n;i++)
        {
            cin>>r[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>g[i];
            
        }*/
        ll e[m];
        queue<ll>r;
        queue<ll>g;
        //queue<ll>r,g;
        for(i=0;i<n;i++)
        {
            cin>>j;
            r.push(j);
        }
        for(i=0;i<n;i++)
        {
            cin>>j;
            g.push(j);
        }
        for(i=0;i<m;i++)
        {
            cin>>e[i];
        }
        ll cr=0;
        ll cg=0;
        i=0;
        while(!r.empty())
        {
           if(r.front()>g.front())
           {
               cr++;
               if(i<m)
               {
                   r.push(e[i]);
                   g.push(e[i+1]);
               }
           }
           if(g.front()>r.front())
           {
               cg++;
               if(i<m)
               {

                   g.push(e[i]);
                   r.push(e[i+1]);
               }
           }
            r.pop();
            g.pop();
            i+=2;
        }
        if(cr>cg)
        {
            cout<<"Radhesh wins"<<endl;
        }
        else if(cg>cr)
        {
            cout<<"Geethakoomaree wins"<<endl;
        }
        else
        {
            cout<<"Tie"<<endl;
        }
    }
    
}