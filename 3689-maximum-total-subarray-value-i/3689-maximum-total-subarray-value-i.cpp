class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        long long mini=1e9;
        long long maxi=INT_MIN;
        long long total=0;
        for(int i=0;i<n;i++){
            if(mini>=nums[i]){
                mini=nums[i];
            }
            if(maxi<=nums[i]){
                maxi=nums[i];
            }
        }
        total+=(maxi-mini);
        total=total*k;
        return total;
        
    }
};