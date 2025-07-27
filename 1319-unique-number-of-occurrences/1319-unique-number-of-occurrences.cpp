class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        unordered_set<int>s;
        int n=arr.size();
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        int count=0;
        for(auto x:m){
            count++;
        }
        for(auto x:m){
            s.insert(x.second);
        }
        if(s.size()==count) return true;
        return false;
            
           
    }
};