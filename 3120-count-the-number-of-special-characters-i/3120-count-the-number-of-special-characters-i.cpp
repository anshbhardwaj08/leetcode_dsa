class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count=0;
        unordered_set<char>s;
        for(int i=0;i<word.size();i++){
            s.insert(word[i]);
        }
        for(auto i:s){
            int a=int(i);
            
                
            
                if(a>=65 && a<=90){
                    if(s.find(char(a+32))!=s.end()){
                        count++;
                    }
                    
                }
                if(a>=97 && a<=122){
                    if(s.find(char(a-32))!=s.end()){
                        count++;
                    }
                }
                
            
        }
        return count/2;
    }
};