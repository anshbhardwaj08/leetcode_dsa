class Solution {
public:
    bool isprime(int n){
    if(n<=1) return false;
    for(int i=2;i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;

}
    int diagonalPrime(vector<vector<int>>& nums) {
        int mx=0;
        int n=nums.size();
        int i=0;
        while(i<n){
            if(isprime(nums[i][i])){
                mx=max(mx,nums[i][i]);
            }
            if(isprime(nums[i][n-i-1])){
                mx=max(mx,nums[i][n-i-1]);
            }
            i++;
        }
        return mx;
    }
};