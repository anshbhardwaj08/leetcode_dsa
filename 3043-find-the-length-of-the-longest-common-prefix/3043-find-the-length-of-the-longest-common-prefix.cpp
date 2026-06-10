class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> st;


        for(int x : arr1){

            string s = to_string(x);

            int prefix = 0;

            for(char ch : s){

                prefix = prefix * 10 + (ch-'0');

                st.insert(prefix);
            }
        }


        int ans = 0;


        for(int x : arr2){

            string s = to_string(x);

            int prefix = 0;

            for(char ch : s){

                prefix = prefix*10 + (ch-'0');

                if(st.find(prefix)!=st.end()){
                    ans=max(ans,(int)to_string(prefix).size());
                }
            }
        }


        return ans;
    }
};