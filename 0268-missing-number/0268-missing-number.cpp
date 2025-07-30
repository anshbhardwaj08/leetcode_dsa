class Solution {
public:
    int missingNumber(vector<int>& v) {
        sort(v.begin(),v.end());
        int sum=0;
        int n=v.size();
        for(int i=0;i<=n;i++){
            sum=sum+i;

        }
        int givensum=0;
        for(auto i: v){
            givensum=givensum+i;

        }
        return sum-givensum;

    }
};