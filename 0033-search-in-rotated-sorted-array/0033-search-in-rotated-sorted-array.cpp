class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1 && nums[0]==target) return 0;
        if(n==1 && nums[0]!=target) return -1;
        if(n==2 && nums[1]==target) return 1;
        int hi=n-1;
        int lo=0;
        if(nums[hi]==target) return hi;
        if(nums[lo]==target) return lo;
        
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(target==nums[mid]){
                return mid;
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
        return -1;
    }
};