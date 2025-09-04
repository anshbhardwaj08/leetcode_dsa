class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        vector<int>ans(2,-1);
        if(n==0) return {-1,-1};
        if(n==1 && nums[0]==target) return {0,0};
        if(n==2 && nums[0]==target && nums[1]==target) return {0,1};
    
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<target){
                lo=mid+1;
            }
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else{
                ans[0]=mid;
                hi=mid-1;
                
            }
        }
        hi=n-1;
        lo=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<target){
                lo=mid+1;
            }
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else{
                ans[1]=mid;
                lo=mid+1;
                
            }
        }


        return ans;
    }
};