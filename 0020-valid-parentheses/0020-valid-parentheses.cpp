class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        
        if(n%2!=0) return false;
        stack<char>st;

        int i=0;
        while(i<n){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{' ){
                st.push(s[i]);
            }
            else if(st.size()==0) return false;
            else if(st.top()!='(' && s[i]==')'){
                return false;
            }
            else if(st.top()!='{' && s[i]=='}'){
                return false ;
            }
            else if(st.top()!='[' && s[i]==']'){
                return false ;
            }
            else{
                st.pop();
            }
            i++;
        }
        if(st.size()!=0) return false;
        return true;





    }
};