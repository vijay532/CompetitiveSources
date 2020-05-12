/*https://www.spoj.com/problems/ACODE/ */
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
/*
25114
1111111111
3333333333
0
2 5 1 1 4, 2 5 1 14, 2 5 11 4, 25 1 1 4, 25 11 4, 25 1 14   
*/
int main()
{
    ll t,i,n,j,k,l,m,s;
    while(1)
    {
        string str;
        cin>>str;
        //cout<<str<<" ";
        string s="0";
        l=str.length();
        //cout<<l<<" ";
        ll dp[l+1]={0};
        dp[0]=1,dp[1]=1;
        if(str!=s)
        {
            for(i=2;i<=l;i++)
            {
                if(str[i-1]-'0'!=0)
                {
                    dp[i]+=dp[i-1];
                }
                k=((str[i-2]-'0')*10)+(str[i-1]-'0');
                //cout<<k<<" ";
                if(k>=10 && k<=26)
                {
                    dp[i]+=dp[i-2];
                }
                //cout<<dp[i]<<" ";
            }
            cout<<dp[l]<<endl;
        }
        else
        {
            break;
        }
    }
} 