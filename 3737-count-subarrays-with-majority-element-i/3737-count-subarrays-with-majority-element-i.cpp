class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int size=1;
            int count=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target){
                    count++;
                }
                size=j-i+1;
                if(2*count>size){
                    ans++;
                }
                

            }
        }
        return ans;
    }
};