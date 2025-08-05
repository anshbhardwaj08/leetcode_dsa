class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>st;
       
        
        string p="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(st.size()>0){
                    p+=s[i];
                }
                st.push(s[i]);
                
            }
            if(s[i]==')'){
                
                st.pop();
                
                if(st.size()>0){
                    p+=s[i];
                    
                    
                }
                if(st.size()==0){
                    continue;
                }
            }
            
        }
        return p;

    }
};