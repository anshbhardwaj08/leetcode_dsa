class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        vector<int>suffix(n+1,0);
        vector<int>prefix(n+1,0);
        vector<int>ans(n+1,0);
        int count=0;
        int ct=0;

        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                count++;
                
                
            }
            prefix[i+1]=count;
            
        }
        prefix[n]=count;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='Y'){
                ct++;
                
                
            }
            suffix[i]=ct;
        }
        
        for(int i=0;i<n+1;i++){
            ans[i]=suffix[i]+prefix[i];
        }
        int mn=INT_MAX;
        for(int i=0;i<n+1;i++){
            mn=min(mn,ans[i]);
        }
        int idx=-1;
        for(int i=0;i<n+1;i++){
            if(ans[i]==mn){
                idx=i;
                break;
            }
        }
        return idx;
    }
};