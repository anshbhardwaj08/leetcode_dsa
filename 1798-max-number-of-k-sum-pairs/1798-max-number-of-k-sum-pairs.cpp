class Solution {
public:

    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count = 0;

        for (int num : nums) {
            int x = k - num;

            if (m[x] > 0) {
                // Pair found
                m[x]--;
                count++;
            } 
            else {
                // No pair yet, store num
                m[num]++;
            }
        }

        return count;
    }
    
};