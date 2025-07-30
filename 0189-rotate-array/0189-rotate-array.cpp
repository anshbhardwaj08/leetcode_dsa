class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int n=v.size();
        if(k>=n){
            k=k%n;
        }
        reverse(v.begin()+n-k,v.end());
        reverse(v.begin(),v.end()-k);
        reverse(v.begin(),v.end());
    }
};