
/* helpful blog 
http://isolvedaproblem.blogspot.com/2012/02/silly-sort.html
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#define ll long long 
using namespace std;
/*
3
3 2 1
4
8 1 2 4
5
1 8 9 7 6
6
8 4 5 3 2 7
0
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,j,k,l;
    cin>>n;
    ll count=0;
    while(n!=0)
    {
        count++;
        ll a[n],c[n];
        bool visit[10001]={false};
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            c[i]=a[i];
        }
        sort(c,c+n);  // resultant array order
        ll min_element=c[0];
        ll place[10001];
        for(i=0;i<n;i++)
        {
            place[c[i]]=i;
            //cout<<place[i]<<" ";
        }
        /*for(i=0;i<n+2;i++)
        {
            cout<<place[i]<<" ";
        }*/
        ll res,ans=0;
        for(i=0;i<n;i++)
        {
            ll p=a[i];
            if(visit[p]=false && place[p]==i)
            {
                continue;
            }
            else if(visit[p]==false)
            {
                visit[p]=true;
                ll sum=p;  // sum of cycle 
                ll val=a[place[p]];  //next element in cycle
                ll cycle=1;   // min cycle length
                ll cyclemin=p;
                while(visit[val]==false)
                {
                    sum+=val;
                    cycle++;
                    visit[val]=true;
                    cyclemin=min(cyclemin,val);
                    val=a[place[val]];
                }
                sum=sum-cyclemin;
                ll op1,op2;
                op1=sum+(cycle-1)*cyclemin;
                if(cyclemin!=min_element)
                {
                    ll op2=min_element*(cycle-1)+sum+2*(min_element+cyclemin);
                    res=min(op2,op1);
                }
                else
                {
                    res=op1;
                }
                ans+=res;
            }
            //cout<<ans<<endl;
        }
        cout<<"Case "<<count <<": "<<ans<<endl;
        cin>>n;
    }
}
