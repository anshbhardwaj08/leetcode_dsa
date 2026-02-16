class Solution {
public:
    int reverseBits(int n) {
        string result="";
        while(n>=1){
            string a=to_string(n%2);
            result=result+a;
            n=n/2;

        }
        if(result.size()!=32){
            while(result.size()!=32){
                result=result+'0';
            }
        }
        int ans=stoi(result,NULL,2);
        return ans;
    }
};