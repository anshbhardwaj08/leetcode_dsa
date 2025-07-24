class Solution {
public:
    int countDistinctIntegers(vector<int>& v) {
        int n=v.size();
        for(int i=0;i<n;i++){
            long long a=0;
            int j=0;
            long long x=v[i];
            while(x!=0){
                a=a*10 +(x%10);
                
                x=x/10;
                j++;
            }
            v.push_back(a);
        }
        unordered_set<int >s;
        for(int i=0;i<v.size();i++){
            s.insert(v[i]);
        }
        return s.size();
        
    }
};