class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        int s=INT_MAX;
        for(int i=0;i<v.size();i++){
            string b=v[i];
            int a=b.size();
            s=min(s,a);
        }// min size is s

        int i=0;
        while(i<s){
            
            char cmpt=v[0][i];
            int j=1;
            while(j<v.size()){
                if(v[j][i] != cmpt) {
                    return ans; // mismatch found
                }
                
                j++;
            }
            ans+=cmpt;
            i++;
            
        }
        return ans;

        
    }
};