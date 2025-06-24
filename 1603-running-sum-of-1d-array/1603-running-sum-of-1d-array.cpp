class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        int i=0;
        while(i<n){
            if(i>0){
                v.push_back(nums[i]+v[i-1]);
            }
            else{
                v.push_back(nums[i]);
            }
            i++;

        }
        return v;
    }
};