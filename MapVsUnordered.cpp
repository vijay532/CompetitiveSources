#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
    string s;
    cin>>s;
    map<char,ll>m;
    map<char,ll>:: iterator it;
    unordered_map<char,ll>om;
    unordered_map<char,ll>:: iterator it1;
    for(int c:s) //O(n*logn)
    {
        m[c]++;
    }
    for(int c:s) // O(n*1)
    {
        om[c]++;
    }
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<it->second;
    }
    cout<<endl;
    for(it1=om.begin();it1!=om.end();it1++)
    {
        cout<<it1->second;
    }
}