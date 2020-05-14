/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        //int findPivot(nums,0,n-1);
        int p=findPivot(nums,0,n-1);
        //cout<<p<<" "; 
        if(p==-1)
        {
            return bs(nums,0,n-1,target);
        }
        if(target==nums[p])
        {
            return p;
        }
        if(nums[0]<=target)
        {
            return bs(nums,0,p-1,target);
        }
        return bs(nums,p+1,n-1,target);
        //return p;
    }
    
    int findPivot(vector<int>&v,int low,int high)
    {
        if(high<low)
        {
            return -1;
        }
        if(high==low)
        {
            return low;
        }
        int mid=(low+high)/2;
        if(mid<high && v[mid]>v[mid+1])
        {
            return mid;
        }
        if(mid>low && v[mid]<v[mid-1])
        {
            return (mid-1);
        }
        if(v[mid]<=v[low])
        {
            return findPivot(v,low,mid-1);
        }
        return findPivot(v,mid+1,high);
    }
    
    int bs(vector<int>&v,int low,int high,int key)
    {
        if(high<low)
        {
            return -1;
        }
        //cout<<low<<" "<<high<<" ";
        int mid=(low+high)/2;
        //cout<<mid<<" ";
        if(key==v[mid])
        {
            return mid;
        }
        if(key>v[mid])
        {
            return bs(v,mid+1,high,key);
        }
        return bs(v,low,mid-1,key);
    }

};