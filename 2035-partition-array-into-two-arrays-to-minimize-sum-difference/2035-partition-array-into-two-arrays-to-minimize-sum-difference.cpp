class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        
        int N = nums.size();
        int n = N / 2;

        vector<vector<int>> left(n + 1), right(n + 1);

        // Generate all subsets
        for(int mask = 0; mask < (1 << n); mask++){

            int sum1 = 0;
            int sum2 = 0;
            int count = 0;

            for(int i = 0; i < n; i++){

                if(mask & (1 << i)){

                    sum1 += nums[i];
                    sum2 += nums[i+n];

                    count++;
                }
            }

            left[count].push_back(sum1);
            right[count].push_back(sum2);
        }


        // Sort right half for binary search
        for(int i=0; i<=n; i++){
            sort(right[i].begin(), right[i].end());
        }


        int total = 0;

        for(auto x: nums){
            total += x;
        }


        int ans = INT_MAX;


        // Pick i elements from left
        for(int i = 0; i <= n; i++){

            // Need n-i elements from right
            vector<int>& v = right[n-i];


            for(auto sumLeft : left[i]){

                // we want total/2 approximately
                int need = total/2 - sumLeft;


                auto it = lower_bound(v.begin(), v.end(), need);


                if(it != v.end()){

                    int s1 = sumLeft + *it;
                    int s2 = total - s1;

                    ans = min(ans, abs(s1-s2));
                }


                if(it != v.begin()){

                    it--;

                    int s1 = sumLeft + *it;
                    int s2 = total - s1;

                    ans = min(ans, abs(s1-s2));
                }
            }
        }


        return ans;
    }
};