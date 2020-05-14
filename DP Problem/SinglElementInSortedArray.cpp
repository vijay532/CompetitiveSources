/*
https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<high)
        {
            int mid=(low+high)>>1;
            if(mid%2)
            {
                if(nums[mid]==nums[mid+1])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
                
            }
            else
            {
                if(nums[mid]==nums[mid-1])
                {
                    high=mid;
                }
                else 
                {
                    low=mid;
                }
            }
        }
        return nums[low];
       
    }
};