class Solution {
public:
    int maxDepth(string s) {
        
        int count=0;
        int ct=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                ct=max(ct,count);
            }
            if(s[i]==')' ){
            
                count--;

            }
           
        }
        return ct;
    }
};