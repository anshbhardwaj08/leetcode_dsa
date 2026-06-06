class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int spend=0;
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int c=0;
        for(int i=n-1;i>=0;i--){

            if(c==2){
                c=0;
                continue;
            }
            else{
                spend+=cost[i];
                c+=1;
            }
        }
        return spend;
    }
};