class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        if(s.size()==0){
            return 0;
        }
        sort(g.begin(),g.end());
        reverse(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0;
        int i=g.size()-1;
        int count=0;
        while( j<=s.size()-1 && i>=0){
            if(s[j]>=g[i] && i>=0){
                count++;
                j++;
                g.pop_back();
                i=g.size()-1;
            }
            else{
                j++;
            }
        }
        return count;
    }
};