class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int count=0;
        while(i<n){
            int j=i;
            int product=1;
            while(j<n){
                product=product*nums[j];
                if(product<k){
                    count++;
                    j++;
                }
                else{
                    break;
                }

            }
            i++;
        }
        return count;
    }
};