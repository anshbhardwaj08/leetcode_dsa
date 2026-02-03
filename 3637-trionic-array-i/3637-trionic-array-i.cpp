class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()<4){
            return false;
        }
        int p=0;
        int q=0;
        int i=1;
        while(i<n ){
            if(nums[i]>nums[i-1]){
                p=i;
                i++;
            }
            else if(nums[i]==nums[i-1]){
                return false;
            }
            else{
                break;
            }
            
        }
        if(p>n-3){
            return false;
        }
        while(i<n && q<n-1 && p!=q){
            if(nums[i-1]>nums[i]){
                q=i;
                i++;
            }
            else if(nums[i]==nums[i-1]){
                return false;
            }
            else{
                break;
            }
        }
        if(q==n-1){
            return false;
        }
        while(i<n && q!=n-1){
            if(nums[i-1]<nums[i]){
                i++;

            }
            else if(nums[i-1]==nums[i] || nums[i-1]>nums[i]){
                return false;
            }
            
        }
        return true;
    }
};