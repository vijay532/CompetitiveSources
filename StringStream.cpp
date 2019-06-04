/*
clear() — to clear the stream
str() — to get and set string object whose content is present in stream.
operator << — add a string to the stringstream object.
operator >> — read something from the stringstream object

stringstream class is extremely useful in parsing input.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
2
2
3 5
8 100
3
5 100 1
2
5 100
*/
int main() 
{
    ll t,n,i,l,r,sum,temp,rem;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>n;
        string str;
        ll count=0;
        for(i=0;i<n;i++)
        {
            getline(cin,str);
            stringstream s(str);
            string word;
            while(s >> word)
            {
                count++;
                cout<<word<<" "<<endl;
            }
        }
    }
  
}
