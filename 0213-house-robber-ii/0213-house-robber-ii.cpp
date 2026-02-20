class Solution {
public:
vector<int>dp;
    int f(vector<int>& nums, int i, int e){
        
        if(i==e){
            return nums[i];
        }
        if(i==e-1){
            return max(nums[i],nums[i+1]);
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=max(nums[i]+f(nums,i+2,e),0+f(nums,i+1,e));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        dp.clear();
        dp.resize(105,-1);
        int first=f(nums,0,nums.size()-2);
        dp.clear();
        dp.resize(105,-1);
        int second=f(nums,1,nums.size()-1);
        return max(first,second);

    }
};