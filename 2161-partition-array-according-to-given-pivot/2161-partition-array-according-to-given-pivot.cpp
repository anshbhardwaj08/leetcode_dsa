class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>v1;
        vector<int>v2;
        vector<int>same;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                v1.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                same.push_back(nums[i]);
            }
            else{
                v2.push_back(nums[i]);
            }
        }
        for(int i=0;i<v1.size();i++){
            ans.push_back(v1[i]);
        }
        for(int i=0;i<same.size();i++){
            ans.push_back(same[i]);
        }
        for(int i=0;i<v2.size();i++){
            ans.push_back(v2[i]);
        }
        return ans;

    }
};