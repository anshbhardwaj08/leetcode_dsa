class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        stack<int>st;
        st.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=st.top()){
                st.push(nums[i]);
            }
            
        }
        nums.clear();
        int n=st.size();
        stack<int>a;
        for(int i=0;i<n;i++){
            a.push(st.top());
            st.pop();
        }
        for(int i=0;i<n;i++){
            nums.push_back(a.top());
            a.pop();
        }



        return nums.size();
        
    }
};