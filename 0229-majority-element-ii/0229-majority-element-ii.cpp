class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        if(n>=2){
            if(nums[0]==nums[1] && n/3<1 ){
                int x=nums[0];
                vector<int>v;
                v.push_back(x);
                return v;
            };
        }
        
        if(n/3<1) return nums;
        
        vector<int>ans;
        int a=nums.size();
        for(auto x: m){
            if(x.second > (a/3)){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};