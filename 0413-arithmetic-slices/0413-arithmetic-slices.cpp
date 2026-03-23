class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        if(nums.size()==3){
            if(nums[0]-nums[1]==nums[1]-nums[2]){
                return 1;
            }
            else{
                return 0;
            }
        }
        int n=nums.size();
        int i=0;
        int k=3;
        int diff=nums[1]-nums[0];
        int count=0;
        bool flag=true;
        while(i<n-k+1){
            int j=i+2;
            int d=nums[j-1]-nums[i];
            
            while(j<n){

                if(nums[j]-nums[j-1]==d){
                    count++;
                    j++;
                    flag=true;
                }
                else{
                    flag=false;
                    break;
                }
                
            }
            i++;
        }
        return count;

        

    }
};