class Solution {
public:

    int fact(int c,int comp){
        int i=1;
        int a=1;
        
        while(i<=c){
            a=a*i;
            i++;
        }
        int j=1;
        int b=1;
        while(j<c-2){
            b=b*j;
            j++;
        }
        a=a/(comp*b);
        return a;

    }
    int rev(int a){
        int r=0;
        while(a>0){
            r=r*10;
            r=r+(a%10);
            a=a/10;

        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        int s=nums.size();
        unordered_map<int,int>m;
        
        for(int i=0;i<s;i++){
            nums[i]=nums[i]-rev(nums[i]);
        }
        int count=0;
        for(auto i:nums){
            if(m.find(i)!=m.end()){
                count=count%1000000007;
                count=count+m[i];
                m[i]++;
            }
            else{
                m[i]++;
            }
        }
        
        return count%1000000007;
        
    }
};