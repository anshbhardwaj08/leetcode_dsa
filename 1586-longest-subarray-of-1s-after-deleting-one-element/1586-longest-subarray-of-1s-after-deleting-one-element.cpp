class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int flips = 0;
        int k=1;
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

                    len = j - i-1;
                    maxlen = max(maxlen, len);
                    
                    while (nums[i]!= 0) {
                        i++;
                    }
                    i++;
                    // no need to reduce the no of flips 
                    j++;
                }
            }
        }
        len = j - i-1;
        maxlen = max(maxlen, len);
        return maxlen;
    }
};