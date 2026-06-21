class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,costs[i]);
        }
        vector<int>freq(mx+1,0);
        for(int i=0;i<n;i++){
            freq[costs[i]]++;
        }
        int index = 0;

    for (int value = 0; value <= mx; value++) {

        while (freq[value] > 0) {
            costs[index] = value;
            index++;
            freq[value]--;
        }
    }
    // int i=0;
    int num=0;
    for(int i=0;i<n;i++){
        if(coins>=costs[i]){
            num++;
            coins-=costs[i];
        }
        else{
            break;
        }
    }
    // while(coins>=costs[i]){
    //     coins=coins-costs[i];
    //     num++;
    //     i++;
    // }
    return num;
    

    }
};