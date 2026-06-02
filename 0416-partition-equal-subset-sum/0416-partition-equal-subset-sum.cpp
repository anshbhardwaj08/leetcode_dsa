class Solution {
public:
    vector<vector<int>>dp;
    bool solve(vector<int>& nums, int i , int target){
        if(i==0){
            return (nums[i]==target);
        }
        if(target==0){
            return true;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool not_take=solve(nums,i-1,target);
        bool take =false;
        if(target>=nums[i]){
            take=solve(nums,i-1,target-nums[i]);
        }
        return dp[i][target]=take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if(target%2!=0){
            return false;
        }
        dp.clear();
        dp.resize(nums.size(),vector<int>(target+1,-1));
        bool ans=solve(nums,nums.size()-1,target/2);
        return ans;

    }
};