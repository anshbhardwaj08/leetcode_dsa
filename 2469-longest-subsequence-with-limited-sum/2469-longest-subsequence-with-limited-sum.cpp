class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        sort(nums.begin(),nums.end());
        int k=1;
        while(k<n){
            nums[k]=nums[k]+nums[k-1];
            k++;
        }
        vector<int>answer;

        // for(int i=0;i<m;i++){
        //     int len=0;
        //     for(int j=0;j<n;j++){
        //         if(nums[j]>queries[i]) break;
        //         else{
        //             len++;
        //         }
        //     }
        //     answer.push_back(len);
        // }
 
        int i=0;
        
        
        while(i<m){
            int size=0;
            int j=0;
            while(j<n){
                if(nums[j]>queries[i]){
                    
                    break;

                } 
                else{
                    size++;
                    
                }
                j++;
                
                
            }
            answer.push_back(size);
            
            i++;
        }

        return answer;
    }
};