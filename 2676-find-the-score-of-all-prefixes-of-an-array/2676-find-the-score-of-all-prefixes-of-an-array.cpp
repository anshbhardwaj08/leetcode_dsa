class Solution {
public:
    vector<long long> findPrefixScore(vector<int >& ans) {
        long long mx=INT_MIN;
        vector<long long>nums(ans.size(),0);
        for(int i=0;i<ans.size();i++){
            if(ans[i]>mx){
                mx=ans[i];
            }
            nums[i]=ans[i]+mx;
        }
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};