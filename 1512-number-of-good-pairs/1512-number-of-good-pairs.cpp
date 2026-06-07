class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(101,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(freq[nums[i]]>0){
                count+=freq[nums[i]];
                freq[nums[i]]++;

            }
            else{
                freq[nums[i]]++;
            }
            
        }
        return count;
    }
};