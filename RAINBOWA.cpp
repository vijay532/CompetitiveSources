
/*
https://www.codechef.com/AUG17/problems/RAINBOWA/
*/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
    long long t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        int b[n];
        int c[n];
        int flag=1;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n/2;i++)
        {
            b[i]=a[i];
        }
        for(i=0;i<n/2;i++)
        {
            c[i]=a[n-i-1];
        }
        sort(b,b+(n/2));
        sort(c,c+(n/2));
        if(a[n/2]==7)
        {
            for(i=0;i<n/2;i++)
            {
                if(b[i]==c[i]&&flag==1)
                {
                    flag=1;
                    //cout<<"yes"<<endl;
                }
                else
                {
                    
                    flag=0;
                }
                
            }
            if(flag==1)
            {
                cout<<"yes"<<endl;
            }
            else if(flag==0)
            {
                cout<<"no"<<endl;
            }
            
        }
        else
        {
            cout<<"no"<<endl;
        }
        
    }
	// your code goes here
	return 0;
}  