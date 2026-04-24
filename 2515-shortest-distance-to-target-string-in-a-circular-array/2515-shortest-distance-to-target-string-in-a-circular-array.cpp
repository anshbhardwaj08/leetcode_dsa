class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int count=0;
        int n= words.size();
        int i=startIndex;
        if(words[startIndex]==target){
            return 0;
        }
        int steps1=0;
        while(count<words.size()){
            if(words[i]==target){
                
            
                break;
            }
            steps1++;
            i=(i+1)%n;
            count++;
        }
        
        int ct=0;
        int steps2=0;
        int j=startIndex;
        while(ct<words.size()){
            if(words[j]==target){
                
                
                break;
            }
            steps2++;
            j=(j-1+n)%n;
            ct++;
        }
        if(ct==words.size() && count==words.size()){
            return -1;
        }
        return min(steps1,steps2);


    }
};