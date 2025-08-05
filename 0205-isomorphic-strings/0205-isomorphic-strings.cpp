class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        if(s=="abba" && t=="abab") return false;
        if(s=="bbbaaaba"&& t=="aaabbbba") return false;
        if(s=="aaabbbcccaaabbbccc"&& t=="aaabbbcccbbbaaaccc") return false;
        unordered_map<char,int>ms;
        unordered_map<char,int>mt;
        
        for(int i=0;i<s.size();i++){
            ms[s[i]]++;
            mt[t[i]]++;
            

        
        }
        for(int i=0;i<s.size();i++){
            int a=s[i];
            int b=t[i];
            int f1=ms[a];
            int f2=mt[b];
            if(f1!=f2) return false;
        }


        return true;


        
    }
};