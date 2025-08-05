class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        
        for(int i=0;i<goal.size();i++){
            if(s==goal) return true;
            char c=s[0];
            s.erase(0,1);
            s.push_back(c);
        }
        return false;
    }
};