class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool flag=false;

        // for(int i=0;i<nums.size()-2;i++){
        //     for(int j=i+1;j<nums.size()-1;j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             if(nums[i]<nums[j] && nums[j]<nums[k]){
        //                 flag=true;
        //                 break;
        //             }
        //         }
        //         if(flag==true){
        //             break;
        //         }
        //     }
        //     if(flag==true){
        //         break;
        //     }
        // }
        int f=INT_MAX;
        int s=INT_MAX;
        for(int a : nums){
            if(a<=f){
                f=a;
            }
            else if(a<=s){
                s=a;
            }
            else{
                flag=true;
                break;
            }
        }
        return flag;
    }
};