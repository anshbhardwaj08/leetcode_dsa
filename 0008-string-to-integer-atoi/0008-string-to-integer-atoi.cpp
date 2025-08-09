class Solution {
public:
    int myAtoi(string s) {
        if(s.size()==0) return 0;
        string ans="";
        int i=0;
        if(isalpha(s[0])) return 0;
        while(s[i]==' '){
            i++;
        }
        int sign=1;
        if(s[i]=='-' && s[i+1]=='+'){
            return 0;
        }
        if(s[i]=='-'){
            sign=-1;
            i++;
        } 
        if(s[i]=='+' && s[i+1]=='-'){
            return 0;
        }
        if(s[i]=='+'){
            sign=1;
            i++;
        } 

        while(isdigit(s[i]) && i<s.size()){
            ans+=s[i];
            i++;
        } 
        if(ans.size()==0) return 0;
        long double a=0;
        if(!isdigit(s[i]) || i==s.size()){
            a+=stold(ans)*sign;
            
        }
        if(a>INT_MAX) return INT_MAX;
        if(a<INT_MIN) return INT_MIN;
        return a; 
        

    }
};