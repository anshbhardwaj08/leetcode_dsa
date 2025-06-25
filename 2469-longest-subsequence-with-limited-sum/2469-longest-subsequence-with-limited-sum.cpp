class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        sort(nums.begin(),nums.end());
        int i=1;
        while(i<n){
            nums[i]=nums[i]+nums[i-1];
            i++;
        }
        vector<int>answer;

        for(int i=0;i<m;i++){
            int len=0;
            for(int j=0;j<n;j++){
                if(nums[j]>queries[i]) break;
                else{
                    len++;
                }
            }
            answer.push_back(len);
        }
 
        

        return answer;
    }
};