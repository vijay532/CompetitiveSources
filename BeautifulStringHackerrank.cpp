#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
store number and increase */
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt" ,"w",stdout);
    //freopen("err.txt" ,"w",stderr);
    ll t,i,n,l,j,k;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        l=s.length();
        string res,tmp;
        ll flg=0,ind;
        for(i=0;i<(l/2);i++)
        {
            tmp=" ";
            for(ll in=0;in<=i;in++)
            {
                //k=s[in]-'0';
                //cout<<k<<" ";
                //ob<<k;
                //res=ob.str();
                //j=res.length();
                tmp+=s[in];
            }
            tmp.erase(tmp.begin());
            //cout<<tmp<<"ji"<<" ";
            stringstream pp(tmp);
            int k=0;
            pp>>k;
            j=tmp.length();
            //cout<<j<<" "<<tmp<<" "<<k<<" ";
            //ostringstream ob;
            string res=tmp,app;
            while(j<l)
            {
                k++;
                ostringstream ob;
                ob<<k;
                app=ob.str();
                j+=app.length();
                res+=app;
            }
            //cout<<res<<" ";
            if(res.compare(s)==0)
            {
                flg=1;
                ind=i;
                break;
            }
            else
            {
                continue;
            }

        }
        if(flg)
        {
            cout<<"YES"<<" ";
            for(i=0;i<=ind;i++)
            {
                cout<<s[i];
            }
            cout<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    //cout<<t<<" "<<"hello"<<endl;
    return 0;
}