class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count=0;
        
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        
            for(int i=0;i<word.size();i++){
                if(word[i]>=97 && word[i]<=122){
                    mp1[word[i]]=i;
                }
            }
        
            for(int i=word.size()-1;i>=0;i--){
                if(word[i]>=65 && word[i]<=90){
                    mp2[word[i]]=i;
                }
            }
        
        for(auto i:mp1){
            if(mp2.find(i.first-32)!=mp2.end()){
                auto j=mp2.find(i.first-32);
                if(i.second<j->second){
                    count++;
                }
            }
            else{
                continue;
            }
        }
        return count;
            
            
                
            
               
       
    }
};