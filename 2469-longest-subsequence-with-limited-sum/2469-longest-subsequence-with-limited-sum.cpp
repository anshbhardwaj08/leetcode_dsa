class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>ans(m,0);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        
        
        for(int i=0;i<m;i++){
            int hi=n-1;
            int lo=0;
            
            int len=0;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]>queries[i]){
                    hi=mid-1;
                }
                else{
                    len=mid+1;
                    lo=mid+1;
                }

                
            }
            
            ans[i]=len;
        }
        return ans;
    }
};