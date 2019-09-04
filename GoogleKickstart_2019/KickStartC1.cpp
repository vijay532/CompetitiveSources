//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
3
5 3 6 2 3
EEWNS
4 3 3 1 1
SESE
11 5 8 3 4
NEESSWWNESE
*/
ll a[10001][10001];
int main()
{
    ll t,i,j,k,n,q,u,v,st,ed,r,c;
    k=0;
    cin>>t;
    while(t--)
    {
        k++;
        cin>>n>>r>>c>>st>>ed;
        string s;
        cin>>s;
        a[st][ed]=1;
        for(i=0;i<n;i++)
        {
            if(s[i]=='E')
            {
                ed++;
                if(!a[st][ed])
                {
                    a[st][ed]=1;
                }
                else
                {   
                    while(a[st][ed])
                    {
                        //a[r][c]=1;
                        ed++;
                    }
                    a[st][ed]=1;
                }
            }
            else if(s[i]=='S')
            {
                st++;
                if(!a[st][ed])
                {
                    a[st][ed]=1;
                }
                else
                {
                    while(a[st][ed])
                    {
                       st++;
                    }
                    a[st][ed]=1;
                }
            }
            else if(s[i]=='W')
            {
                ed--;
                if(!a[st][ed])
                {
                    a[st][ed]=1;
                }
                else
                {
                    while(a[st][ed])
                    {
                        ed--;
                    }
                    a[st][ed]=1;
                }
                    
            }
            else
            {
                st--;
                if(!a[st][ed])
                {
                    a[st][ed]=1;
                }
                else
                {
                    while(a[st][ed])
                    {
                        //a[r][c]=1;
                        st--;
                    }
                    a[st][ed]=1;
                }
            }
            //cout<<st<<" "<<ed<<" ";
        }
        cout<<"Case #"<<k<<": "<<st<<" "<<ed<<endl;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                a[i][j]=0;
            }
        }
    }
}