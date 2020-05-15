
/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        return    {f_bs(nums,0,nums.size()-1,target),l_bs(nums,0,nums.size()-1,target,nums.size()-1)};
        
    }
    int f_bs(vector<int>&nums,int low,int high,int t)
    {
        if(low<=high)
        {
            int mid=(high+low)/2;
                        
            if(((t>nums[mid-1] || mid==0))&&nums[mid]==t)
            {
                cout<<mid<<" ";
                return mid;
            }
            
            else if(nums[mid]<t)
            {
                return f_bs(nums,mid+1,high,t);
            }
            else
            {
                return f_bs(nums,low,mid-1,t);
            }
        }
        return -1;
    }
    
    int l_bs(vector<int>&nums,int low,int high,int t,int n)
    {
        if(low<=high)
        {
            int mid=(high+low)/2;
            //cout<<mid<<" ";
            if(((mid==n ||  t<nums[mid+1]))&& nums[mid]==t)
            {
                //cout<<mid<<" ";
                return mid;
            }
            else if(nums[mid]<t)
            {
                return l_bs(nums,mid+1,high,t,n);
            }
            else
            {
                return l_bs(nums,low,mid-1,t,n);
            }
        }
        return -1;   
    }
    
};
