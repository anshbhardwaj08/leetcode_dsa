class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        queue<int>q;
        queue<int>s;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                s.push(nums[i]);
            }
            else{
                q.push(nums[i]);
            }

        }
        vector<int>v(n,0);
        for(int i=0;i<n;i+=2){
            v[i]=q.front();
            q.pop();
        }
        for(int i=1;i<n;i+=2){
            v[i]=s.front();
            s.pop();
        }
        return v;
                
    }
};