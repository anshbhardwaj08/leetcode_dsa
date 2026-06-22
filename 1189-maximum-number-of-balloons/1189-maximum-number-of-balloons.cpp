class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int m=text.size();
        vector<int>freq(26,0);
        for(int i=0;i<m;i++){
            freq[text[i]-'a']++;
        }bool flag=true;
        int b=0;
        int a=0;
        int l=0;
        int o=0;
        int n=0;
        for(int i=0;i<freq.size();i++){
            if(i+'a'=='b'){
                b=freq[i];
            }
            else if(i+'a'=='a'){
                a=freq[i];
            }
            else if(i+'a'=='l'){
                l=freq[i];
            }
            else if(i+'a'=='o'){
                o=freq[i];
            }
            else if(i+'a'=='n'){
                n=freq[i];
            }
        }
        int ans=min(b,a);
        int res=min(n,ans);
        int mn=min(l,o);
        if(mn>=2*res){
            return res;
        }
        else{
            for(int i=res;i>=0;i--){
                if(2*i<=mn){
                    res=i;
                    break;
                }
            }

        }
        return res;
    }
};