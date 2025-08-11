class Solution {
public:
    int hammingWeight(int n) {
        // if(n==0) return 0;
        // int a=n-1;
        // int ans= (a&n);
        // if(ans==0) return 1;
        // return ans;
        return __builtin_popcount(n);
    }
};