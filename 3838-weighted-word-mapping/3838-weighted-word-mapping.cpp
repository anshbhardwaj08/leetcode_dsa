class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto s: words){
            int total=0;
            for(char a: s){
                total+=weights[a-'a'];
            }
            total=total%26;
            ans.push_back(char(26-total+96));

        }
        return ans;
    }
};