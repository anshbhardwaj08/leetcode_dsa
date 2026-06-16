class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<s.size();i++){
            if(int(s[i])>=97 && int(s[i])<=122){
                char a=s[i];
                ans.push_back(a);
            }
            else if(s[i]=='*' && ans.size()!=0){
                ans.pop_back();
            }
            else if(s[i]=='#'){
                string b=ans;
                ans=ans+b;
            }
            else{
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};