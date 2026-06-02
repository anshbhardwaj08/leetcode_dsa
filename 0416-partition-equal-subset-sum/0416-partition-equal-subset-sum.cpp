class Solution {
public:
    vector<vector<bool>>dp;
    // bool solve(vector<int>& nums, int i , int target){
    //     if(i==0){
    //         return (nums[i]==target);
    //     }
    //     if(target==0){
    //         return true;
    //     }
    //     if(dp[i][target]!=-1){
    //         return dp[i][target];
    //     }
    //     bool not_take=solve(nums,i-1,target);
    //     bool take =false;
    //     if(target>=nums[i]){
    //         take=solve(nums,i-1,target-nums[i]);
    //     }
    //     return dp[i][target]=take || not_take;
    // }
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if(target%2!=0){
            return false;
        }
        dp.clear();
        dp.resize(nums.size(),vector<bool>(target+1,false));
        // bool ans=solve(nums,nums.size()-1,target/2);
        // return ans;
        for(int i=0;i<nums.size();i++){
            dp[i][0]=true;
        }
        dp[0][nums[0]]=true;
        for(int i=1;i<nums.size();i++){
            for(int k=1;k<=target/2;k++){
                bool not_take=dp[i-1][k];
                bool take =false;
                if(k>=nums[i]){
                    take=dp[i-1][k-nums[i]];
                }
                dp[i][k]=take | not_take;
            }
        }
        return dp[nums.size()-1][target/2];

    }
};