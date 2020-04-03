//g++  5.4.0
//TLE for large test cases

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
2
7 5
ABAACCA
3 6
4 4
2 5
6 7
3 7
3 5
XYZ
1 3
1 3
1 3
1 3
1 3
*/
bool isPalin(string &str)
{
    ll i,l;
    l=str.length();
    unordered_map<char,ll>mp;
    for(i=0;i<l;i++)
    {
        mp[str[i]]++;
    }
    ll count=0;
    for(auto i:mp)
    {
        //cout<<i.first<<" "<<i.second<<" ";
        if(i.second%2)
        {
            count++;
        }
    }
    return(count>1?false:true);
}

ll a[100001][26];
int main()
{
    ll t,p,i,n,q,j,k,l,r;
    p=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        char c;
        for(i=1;i<=n;i++)
        {
            cin>>c;
            //cout<<c<<endl;
            a[i][c-'A']++;
            for(j=0;j<26;j++)
            {
                
                a[i][j]+=a[i-1][j];
                //cout<<a[i][j]<<" ";
            }
            //cout<<endl;
            
        }
        ll count=0;
        while(q--)
        {
            cin>>l>>r;
            ll odd=0;
            //cout<<a[2][0]<<" "<<a[6][2]<<" ";
            for(i=0;i<26;i++)
            {
               
                if((a[r][i]-a[l-1][i])%2)
                {
                    odd++;
                }
            }
            if(odd<=1)
            {
                count++;
            }
            //cout<<count<<" ";
        }
        p++;
        cout<<"Case #"<<p<<": "<<count<<endl;
        for(i=0;i<100001;i++)
        {
            for(j=0;j<26;j++)
            {
                a[i][j]=0;
            }
        }
    }
}