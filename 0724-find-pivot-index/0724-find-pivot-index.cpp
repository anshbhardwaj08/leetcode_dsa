class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>l;
        vector<int>r;
        vector<int>a;
        for(int i=0;i<nums.size();i++){
            a.push_back(nums[i]);
        }
        
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        for(int i=0;i<nums.size();i++){
            l.push_back(nums[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            a[i]=a[i]+a[i+1];
        }
        for(int i=0;i<a.size();i++){
            r.push_back(a[i]);
        }
        int i=0;
        while(i<r.size()){
            if(r[i]==l[i]){
                return i;
            }
            i++;
        }
        return -1;

    }
};