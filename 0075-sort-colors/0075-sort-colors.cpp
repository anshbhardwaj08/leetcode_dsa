class Solution {
public:
    void sp(int a ,int b ,vector<int> &v){
        int temp=v[a];
        v[a]=v[b];
        v[b]=temp;
        return ;
    }
    void sortColors(vector<int>& nums) {
        int lo=0;
        int mid=0;
        int hi=nums.size()-1;
        while(mid<=hi){
            if(nums[mid]==2){
                sp(mid,hi,nums);
                hi--;
                

            }
            else if(nums[mid]==0){
                sp(mid,lo,nums);
                mid++;
                lo++;
            }
            else{
                mid++;
            }
        }

        
    }
};