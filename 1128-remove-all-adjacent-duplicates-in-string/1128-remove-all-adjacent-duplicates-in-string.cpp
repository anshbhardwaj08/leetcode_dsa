class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n=s.size();
        int i=0;
        while(i<n){
            if(st.size()==0){
                st.push(s[i]);
                i++;
            }
            else{
                if(st.top()==s[i]){
                    st.pop();
                    i++;
                }
                else{
                    st.push(s[i]);
                    i++;
                }
            }
        }
        
        stack<char>temp;
        while(st.size()!=0){
            char x=st.top();
            temp.push(x);
            st.pop();
        }
        string ans;
        int j=0;
        while(temp.size()!=0){
            char y=temp.top();
            ans.push_back(y);
            temp.pop();
            

        }
        return ans;

        
    }
};