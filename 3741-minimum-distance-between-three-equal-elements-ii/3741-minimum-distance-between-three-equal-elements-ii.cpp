class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);

            int sz = mp[nums[i]].size();

            if (sz >= 3) {
                int a = mp[nums[i]][sz-3];
                int c = mp[nums[i]][sz-1];

                ans = min(ans, 2 * (c - a));
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};