class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size()!=w2.size()) return false;
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        unordered_map<int,int>h1;
        unordered_map<int,int>h2;
        for(int i=0;i<w1.size();i++){
            m1[w1[i]]++;
        }
        for(int i=0;i<w2.size();i++){
            m2[w2[i]]++;
        }
        for(auto x: m1){
            int l=x.second;
            h1[l]++;
        }
        for(auto y: m2){
            int m=y.second;
            h2[m]++;
        }

        for(auto a: m1){
            if(m2.find(a.first)==m2.end()){
                return false;
            }

        }
        for(auto b: h1){
            int c=b.second;
            int v=b.first;
            if(h2.find(v)!=h2.end()){
                int d=h2[b.first];
                if(c!=d){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;


    }
};