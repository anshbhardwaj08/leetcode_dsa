class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()==0) return 0;
        if(arr.size()==1) return 1;
        unordered_set<int>s;
        for(int ele:arr){
            s.insert(ele);

        }
        vector<int>nums;
        for(int i: s){
            nums.push_back(i);
        }
        if(nums.size()==1) return 1;

        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        if(nums[j+1]==nums[j]+1){
            j++;
        }
        else{
            j++;
            i=j;
        }
        int mxlen=INT_MIN;
        int len=INT_MIN;
        while(j<nums.size()){
            if(nums[j]!=nums[j-1]+1){
                len=j-i;
                mxlen=max(mxlen,len);
                i=j;
                j++;
            }
            else{
                
                j++;
            }
        }
        len=j-i;
        mxlen=max(mxlen,len);
        return mxlen;


        
    }
};