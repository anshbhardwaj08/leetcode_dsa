class Solution {
public:
    int minOperations(string s) {
        int n= s.size();
        int i=1;
        char a=s[0];
        int count=0;
        while(i<n){
            if(s[i]!=a){
                a=s[i];
                i++;
            }
            else{
                count++;
                if(s[i]=='0'){
                    s[i]='1';
                }
                else{
                    s[i]='0';
                }
                a=s[i];
                i++;
            }
        }

        return min(count,n-count);
    }
};