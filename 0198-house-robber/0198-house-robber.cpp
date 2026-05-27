class Solution {
public:
    vector<int>dp;
    int f(vector<int>& nums, int i){
        if(i==0){
            return nums[i];
        }
        if(i<=0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }


        return dp[i]=max(f(nums,i-1),nums[i]+f(nums,i-2));
    }
    int rob(vector<int>& nums) {
        dp.clear();
        
        int n=nums.size();
        dp.resize(n+1,-1);
        int ans=f(nums,n-1);
        return ans;
    }
};