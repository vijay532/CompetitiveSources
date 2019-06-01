class Solution {
public:
    int jump(vector<int>& nums) 
    {
        long long i,j,temp;
        long long n=nums.size();
        vector<long long>dp(n,INT_MAX-1); // to avoid the overflow 
        dp[n-1]=0;
        for(i=n-2;i>=0;i--)
        {
            for(j=i+1;j<=i+nums[i] && j<n;j++)
            {
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
        /*for(i=0;i<n;i++)
        {
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        //cout<<INT_MAX-1<<endl;
        if(dp[0]!=INT_MAX-1 || dp[0]!=0)
        {
            return true;
        }
        else
        {
            return false;
        }
        //return dp[0];
    }
};