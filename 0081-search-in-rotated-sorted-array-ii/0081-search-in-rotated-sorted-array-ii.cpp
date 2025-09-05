class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int n=nums.size();
        if(n==1 && nums[0]==target) return true;
        if(n==1 && nums[0]!=target) return false;
        if(n==2 && nums[1]==target) return true;
        int hi=n-1;
        int lo=0;
        if(nums[hi]==target) return true;
        if(nums[lo]==target) return true;
        
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(target==nums[mid]){
                return true;
            }
            if(nums[lo]==nums[mid] && nums[mid]==nums[hi]){
                lo=lo+1;
                hi=hi-1;
                continue;
            }
            
                if(nums[mid]<=nums[hi]){
                    if(target>=nums[mid] && target<=nums[hi]){
                        lo=mid+1;
                    }
                    else{
                        hi=mid-1;
                    }
                }
                else if(nums[lo]<=nums[mid]){
                    if(target<=nums[mid] && target >=nums[lo]){
                        hi=mid-1;
                    }
                    else{
                        lo=mid+1;
                    }
                }
            
            
        }
        return false;
    }
};