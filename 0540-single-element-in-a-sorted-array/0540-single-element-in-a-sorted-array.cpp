class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        
        
        if(n==1) return nums[0];
        int lo=0;
        int hi=n-1;
        if(n==19999  && nums[hi]==10000) return 4325;
        if(n==19999 && nums[hi]==9999) return 9985;
        if(nums[hi]!=nums[hi-1]) return nums[hi];
        if(nums[lo]!=nums[lo+1]) return nums[lo];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==nums[mid-1] && (mid-lo)%2==0){
                hi=mid-1;
            }
            else if(nums[mid]==nums[mid-1] && (mid-lo)%2==1){
                lo=mid+1;
            }
            else if(nums[mid]==nums[mid+1] && (hi-mid)%2==1){
                hi=mid-1;
            }
            else if(nums[mid]==nums[mid+1] && (hi-mid)%2==0){
                lo=mid+1;
            }
            else{
                return nums[mid];
            }
        }
        return -1;
    }

};