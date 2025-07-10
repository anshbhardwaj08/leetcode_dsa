class Solution {
public:

    void helper(vector<int>& nums,vector<int>ans,vector<vector<int>>&finalans,int idx){
        if(idx==nums.size()){
            finalans.push_back(ans);
            return ;
        }
        helper(nums,ans,finalans,idx+1);
        ans.push_back(nums[idx]);
        helper(nums,ans,finalans,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int idx=0;
        vector<vector<int>>finalans;
        vector<int>ans;
        helper(nums,ans,finalans,idx);
        return finalans;
        
    }
};