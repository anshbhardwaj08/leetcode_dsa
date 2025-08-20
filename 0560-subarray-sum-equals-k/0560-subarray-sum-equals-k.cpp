class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==1){
            if(k<nums[0]){
                return 0;
            }
        }
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        

        
        unordered_map<int,int>s;
        // for(auto x: nums){
        //     s.insert(x);
        // }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k){
                count++;
            }
            
            int a=nums[i]-k;
            if(s.find(a)!=s.end()){
                count+=s[a];
                
            }
            s[nums[i]]++;
        }
        return count; 
    }
};