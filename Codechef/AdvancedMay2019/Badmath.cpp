https://www.codechef.com/ALPAST01/problems/BADMATH/


//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
2
3 5
10_
3 2
1_0
*/
ll n;
vector<string>v;
ll expo(ll p,ll m)
{
    if(m==0)
    {
        return 1;
    }
    else if(m==1)
    {
        return p;
    }
    ll res=expo(p,m/2);
    if(m%2)
    {
        return res*res*p;
    }
    else
    {
        return res*res;
    }
}
void prep(char a[],ll u)
{
    string str=" ";
    for(int i=0;i<n;i++)
    {
        str+=a[i];
    }
    str.erase(str.begin()+0);
    v.push_back(str);
}

void generate(ll i, ll u, char a[])
{
    if(i==u)
    {
       prep(a,u);
       return; 
    }
    a[i]='0';
    generate(i+1,u,a);
    a[i]='1';
    generate(i+1,u,a);
}
int main()
{
    ll i,t,max_underline,count,c,j,p,m,l,k,sum,idx;
    cin>>t;
    while(t--)
    {
        v.clear();
        cin>>n>>m;
        string s;
        cin>>s;
        c=0;
        l=s.length();
        //count=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='_')
            {
                c++;
                //cout<<"ji"<<" ";
            }
        }
        //ll l=expo(2,c);
        char a[c];
        generate(0,c,a);
        max_underline=pow(2,c);
        count=0;
        for(i=0;i<max_underline;i++)
        {
            //cout<<v[i]<<" ";
            string temp=" ";
            temp+=v[i];
            temp.erase(temp.begin()+0);
            k=0;
            string res=" ";
            res+=s;
            res.erase(res.begin()+0);
            for(j=0;j<l;j++)
            {
                if(res[j]=='_')
                {
                    res[j]=temp[k];
                    k++;
                }
                
            }
            //cout<<res<<" ";
            sum=0;
            idx=0;
            for(p=res.length()-1;p>=0;p--)
            {
                if(res[p]=='1')
                {
                    sum+=pow(2,idx);
                }
                idx++;
            }
            if(sum-m*(sum/m)==0)
            {
                count++;
            }
            //cout<<sum<<" ";
        }
        cout<<count<<endl;
    }
}