class Solution {
public:
    int nextGreaterElement(long long a) {
        string nums=to_string(a);
        long long n=nums.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;

            }

        }
        if(idx==-1){
            
            return -1;
        }
        reverse(nums.begin()+idx+1,nums.end());
        int j=-1;
        for(int i=idx; i<n; i++){
            if(nums[i]>nums[idx]){
                j=i;
                break;
            }
        }
        int temp=nums[idx];
        nums[idx]=nums[j];

        nums[j]=temp;
        long long b=stoll(nums);
        if(b>INT_MAX) return -1;
        return b;

     
    }

        
        

    
};