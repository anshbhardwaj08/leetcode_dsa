class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            int j=0;
            int steps=nums[i];
            int count=0;
            if(steps>0){
                int j=i;
                while(count<steps){
                    count++;
                    j++;
                    if(j==n){
                        j=0;
                    }
                    
                }
                result[i]=nums[j];
            }
            if(steps==0){
                result[i]=nums[i];
            }
            if(steps<0){
                steps=abs(steps);
                int j=i;
                while(count<steps){
                    count++;
                    j--;
                    if(j==-1){
                        j=n-1;
                    }
                }
                result[i]=nums[j];
            }
        }
        return result;
    }
};