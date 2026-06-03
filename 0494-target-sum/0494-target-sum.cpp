class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
        int m = arr.size();

        int totalsum = 0;
        for(int x : arr){
            totalsum += x;
        }


        if(totalsum-diff < 0 || (totalsum-diff)%2)
            return 0;


        int k = (totalsum-diff)/2;


        vector<vector<int>> dp(m, vector<int>(k+1,0));


        // initialization
        if(arr[0]==0){
            dp[0][0] = 2;
        }
        else{
            dp[0][0] = 1;
        }


        if(arr[0]!=0 && arr[0]<=k){
            dp[0][arr[0]] = 1;
        }


        for(int i=1;i<m;i++){

            for(int target=0;target<=k;target++){

                int not_take = dp[i-1][target];

                int take = 0;

                if(target >= arr[i]){
                    take = dp[i-1][target-arr[i]];
                }

                dp[i][target] = take + not_take;
            }
        }


        return dp[m-1][k];
    }
};