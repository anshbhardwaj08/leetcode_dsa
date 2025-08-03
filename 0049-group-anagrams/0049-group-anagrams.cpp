class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>m;
        for(auto i: strs){
            
            string s=i;
            sort(s.begin(),s.end());
            if(m.find(s)!=m.end()){
                
                m[s].push_back(i);
            }
            else{
                vector<string>v;
                v.push_back(i);
                m[s]=v;
            }
        }
        for(auto x: m){
            ans.push_back(x.second);
        }
        return ans;
    }
};