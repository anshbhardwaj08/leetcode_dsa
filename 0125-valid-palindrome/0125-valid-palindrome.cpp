class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
    int i=0;
    int n=s.size();
    while(i<n){
        if(isalnum(s[i])){
            ans+=tolower(s[i]);
        }
        i++;
    }
   
    string a;
    for(int i=0;i<ans.size();i++){
        a.push_back(ans[i]);
    }
    reverse(ans.begin(),ans.end());
    if(ans==a) return true;
    return false;

        
    }
};