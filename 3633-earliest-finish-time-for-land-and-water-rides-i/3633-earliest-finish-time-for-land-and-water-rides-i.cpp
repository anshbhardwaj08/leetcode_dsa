class Solution {
public:
    int earliestFinishTime(vector<int>& l, vector<int>& ld,
                           vector<int>& w, vector<int>& wd) {
        
        int ans = INT_MAX;

        int m = l.size();
        int n = w.size();


        // land then water
        for(int i=0;i<m;i++){

            int finishLand = l[i] + ld[i];

            for(int j=0;j<n;j++){

                int finish =
                max(finishLand, w[j]) + wd[j];

                ans = min(ans, finish);
            }
        }


        // water then land
        for(int i=0;i<n;i++){

            int finishWater = w[i] + wd[i];

            for(int j=0;j<m;j++){

                int finish =
                max(finishWater, l[j]) + ld[j];

                ans = min(ans, finish);
            }
        }

        return ans;
    }
};