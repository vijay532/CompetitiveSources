//g++  5.4.0
// https://www.codechef.com/FLPAST01/problems/HASHRAD/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
2
abz
yzz
*/
int main()
{
    ll t,i,n,j,k,l;
    cin>>t;
    while(t--)
    {
        //cout<<t<<endl;
        string s;
        cin>>s;
        map<char,ll>mp;
        ll l=s.length();
        ll sum=0;
        string temp=" ";
        ll flag=0,ne=0,c=0;
        for(i=0;i<l;i++)
        {
            sum+=(s[i]-97);
            temp+=s[i];
            mp[s[i]]++;
        }
        temp.erase(temp.begin()+0);
        sort(temp.begin(),temp.end());
        for(i=0;i<l;i++)
        {
            if(temp[i]!=s[i])  //after sorting equal or not 
            {
                //cout<<"ok";
                ne=1;
                break;
            }
        }
        if(ne==0)
        {
            //cout<<"ji";
            for(auto i:mp)
            {
                if(i.second==l)
                {
                    cout<<"-1"<<endl;
                    c=1;
                    break;
                }
                if(i.second>1)
                {
                    flag=1;
                    break;
                }
            }
            if(c)
            {
                continue;
            }
            else
            {   
                if(flag)
                {
                    //temp.erase(temp.begin()+0);
                    for(i=1;i<l;i++)
                    {
                        if(temp[i]!=temp[i-1])
                        {
                            swap(temp[i],temp[i-1]);
                            break;
                        }
                    }
                    
                    cout<<sum<<" "<<temp<<endl;
                }
                else
                {
                    swap(s[l-1],s[l-2]);
                    cout<<sum<<" "<<s<<endl;
                }
            }
        }
        else
        {
            //cout<<"ji";
            cout<<sum<<" "<<temp<<endl;
            continue;
        }
    }
}