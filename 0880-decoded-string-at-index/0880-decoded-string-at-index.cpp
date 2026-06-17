class Solution {
public:
    string decodeAtIndex(string s, int k) {

        long long len = 0;

        for(char c : s){
            if(c >= 'a' && c <= 'z')
                len++;
            else
                len *= (c-'0');
        }


        for(int i=s.size()-1; i>=0; i--){

            char c = s[i];

            k %= len;

            if(k == 0 && c >= 'a' && c <= 'z'){
                return string(1,c);
            }

            if(c >= 'a' && c <= 'z'){
                len--;
            }
            else{
                len /= (c-'0');
            }
        }

        return "";
    }
};