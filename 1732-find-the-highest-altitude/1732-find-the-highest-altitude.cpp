class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>res(n+1,0);
        int mx=INT_MIN;
        for(int i=1;i<=n;i++){
            res[i]=res[i-1]+gain[i-1];
            mx=max(mx,res[i]);
        }
        mx=max(res[0],mx);
        return mx;

    }
};