class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int flips = 0;
        int maxlen = INT_MIN;
        int len = INT_MIN;
        while (j < nums.size()) {
            if (nums[j] == 1) {
                j++;
            }
            else{
                if(flips < k){
                    flips++;
                    j++;
                }
                else{

                    len = j - i;
                    maxlen = max(maxlen, len);
                    
                    while (nums[i]!= 0) {
                        i++;
                    }
                    i++;
                    
                    j++;
                }
            }
        }
        len = j - i;
        maxlen = max(maxlen, len);
        return maxlen;
    }
};