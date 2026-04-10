class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        int ans = 0;
        int endPos = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                    int len = dp[i][j];

                    // starting index in original string
                    int startOriginal = i - len;

                    // corresponding starting index in original string
                    // from the reversed string side
                    int startReverse = n - j;

                    // valid only if both starts match
                    if (startOriginal == startReverse && len > ans) {
                        ans = len;
                        endPos = i;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return s.substr(endPos - ans, ans);
    }
};