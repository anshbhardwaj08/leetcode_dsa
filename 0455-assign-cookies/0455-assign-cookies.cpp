class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int  n=g.size();
        int  m=s.size();
        int  count=0;
        int  i=0;
        int  j=0;
        
        while(i<=n-1 && j<=m-1){
               
                
            if(s[j]>=g[i]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }

        }
         
        return count;
    }
};