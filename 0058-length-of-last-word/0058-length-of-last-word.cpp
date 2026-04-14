class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int cnt=0;
        int len=0;
        for(int i=n-1;i>=0;i--){
            while(s[i]==' ' && len==0){
                
                    i--;
                    cnt++;
                

            }
            if(s[i]==' '){
                break;
            }
            len++;
        }
        return len;
    }
};