class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        int b=0;
        int c=0;
        int dis=INT_MAX;
        bool flag=false;
        for(int i=0;i<n-2;i++){
            a=i;
            for(int j=i+1;j<n-1;j++){
                if(nums[i]==nums[j]){
                    b=j;
                    for(int k=j+1;k<n;k++){
                        if(nums[k]==nums[j]){
                            c=k;
                            flag=true;
                            int d=abs(a-b)+abs(b-c)+abs(a-c);
                            dis=min(dis,d);
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                }
                else{
                    continue;
                }
            }
        }
        if(flag==false){
            return -1;
        }
        return dis;
    }
};