class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans;
        int n=prices.size();

        int i=0;
        while(i<n-1){
            int j=i+1;
            int count=0;
            while(j<n){
                if(prices[i]>=prices[j]){
                    ans.push_back(prices[i]-prices[j]);
                    count++;
                    break;
                }
                j++;
            }
            if(count==0){
                ans.push_back(prices[i]);
            }
            i++;
        }
        ans.push_back(prices[n-1]);
        return ans;
    }
};