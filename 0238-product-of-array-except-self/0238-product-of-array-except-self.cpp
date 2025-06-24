class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,0);
        int product=1;
        int i=0;
        while(i<n){
            if(i==0){
                v[i]=product;
            }
            else{
                product=product*nums[i-1];
                v[i]=product;
            }
            i++;
        }
        int newproduct=1;
        int j=n-1;
        while(j>=0){
            if(j==n-1){
                v[j]=newproduct*v[j];

            }
            else{
                newproduct=newproduct*nums[j+1];
                v[j]=v[j]*newproduct;
            }
            j--;
        }
        return v;
        
    }
};