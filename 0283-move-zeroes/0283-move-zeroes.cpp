class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stack<int>st;
        queue<int>gt;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) st.push(0);
            else{
                gt.push(nums[i]);
            }
        }
        nums.clear();
        int n=gt.size();
        for(int i=0;i<n;i++){
            nums.push_back(gt.front());
            gt.pop();
        }
        int m=st.size();
        for(int i=0;i<m;i++){
            nums.push_back(st.top());
            st.pop();
        }
        
    }
};