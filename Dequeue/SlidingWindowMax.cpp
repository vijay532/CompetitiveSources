/*
https://leetcode.com/problems/sliding-window-maximum/
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int i,l=nums.size();
        deque<int>q;
        vector<int>res;
        for(i=0;i<k;i++)
        {
            while(!q.empty() && nums[i]>=nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        for(;i<l;i++)
        {
            res.push_back(nums[q.front()]);
            while(!q.empty() && q.front()<=i-k)
            {
                q.pop_front();
            }
            while(!q.empty() && nums[i]>=nums[q.back()])
            {
                q.pop_back();
                
            }
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);
        return res;
    }
    
};