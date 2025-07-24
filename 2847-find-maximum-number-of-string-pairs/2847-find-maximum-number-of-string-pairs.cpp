class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        int n=words.size();
        for(int i=0;i<n;i++){
            s.insert(words[i]);
        }
        int count=0;
        int i=0;
        while(i<n){
            string v=words[i];
            reverse(v.begin(),v.end());
            int j=0;
            int x=0;
            while(j<=i){
                if(words[j]==v){
                    x=x+1;
                    break;
                }
                j++;
            }
            if(x==0){
                if(s.find(v)!=s.end()){
                    count++;
                }
            }
            
            i++;

        }
        return count;
    }
};