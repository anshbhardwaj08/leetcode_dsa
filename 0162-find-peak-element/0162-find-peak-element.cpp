class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        // if 
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int lo=1;
        int hi=n-2;
        // if(hi<lo){
        //     if(nums[lo]>nums[hi]) return lo;
        //     if(nums[lo]<nums[hi]) return hi;
        //     if(nums[lo]==nums[hi]) return hi;
        // }
        // if(hi==lo){
        //     if(nums[hi]==nums[lo])
        // }

        

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            else if(nums[mid]>nums[mid+1]){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        

        }
        return 0;
    }
};