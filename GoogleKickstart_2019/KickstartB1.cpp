//g++  5.4.0

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
        if(i.second%2)
        {
            count++;
        }
    }
    return(count>1?false:true);
}
int main()
{
    ll t,i,n,q,j,k,l,r;
    j=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        string s;
        cin>>s;
        ll count=0;
        while(q--)
        {
            cin>>l>>r;
            string temp=" ";
            for(i=l-1;i<r;i++)
            {
                temp+=s[i];
            }
            temp.erase(temp.begin()+0);
            ll p=isPalin(temp);
            if(p==1)
            {
                count++;
            }
        }
        j++;
        cout<<"Case #"<<j<<": "<<count<<endl;
        
        
    }
}