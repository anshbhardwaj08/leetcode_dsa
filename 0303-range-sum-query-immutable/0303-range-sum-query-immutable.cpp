class NumArray {
public:
    vector<int>v;
    
    NumArray(vector<int>& nums) {
        this->v=nums;
        
    }
    
    int sumRange(int left, int right) {
        
        int ans=0;
        while(left<=right){
            ans=v[left]+ans;
            left++;
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */