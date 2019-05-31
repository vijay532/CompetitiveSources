#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int t;
int main() 
{
	stack<char>s;
	cin>>t;
	string str;
	while(t--)
	{
		cin>>str;
		ll flag=0;
		for(char c:str)
		{
			if(s.empty() && c==')')
			{
				flag=1;
				break;
			}
			if(c==')')
			{
				s.pop();
			}
			else
			{
				s.push(c);
			}
		}
		if(s.empty() && flag==0)
		{
			cout<<"balanced"<<endl;
		}
		else
		{
			cout<<"not balanced"<<endl;
		}
	}
	// your code goes here
	return 0;
}