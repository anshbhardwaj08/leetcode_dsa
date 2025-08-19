class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        for(int e=0;e<n;e++){
            if(nums[e]%2==0){
                nums[e]=0;
            }
            else{
                nums[e]=1;
            }

        }
        for(int a=1;a<nums.size();a++){
            nums[a]=nums[a]+nums[a-1];
        }
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(nums[i]==k){
                count++;
            }
            int c=nums[i]-k;
            if(m.find(c)!=m.end()){
                count+=m[c];
            }
            m[nums[i]]++;
        }
        return count;

    }
};