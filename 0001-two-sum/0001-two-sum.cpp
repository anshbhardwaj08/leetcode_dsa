class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        bool flag =false;
        int n=nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    flag=true;
                    res.push_back(i);
                    res.push_back(j);                 
                    break;
                }


            }
        }
        if(flag==false){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        };
        return res;
    }
};