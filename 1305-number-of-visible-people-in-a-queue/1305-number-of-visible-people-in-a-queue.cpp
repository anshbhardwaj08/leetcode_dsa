class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& v) {
        vector<int>a;
        int n=v.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int count=0;
            
            while(st.size()>0 && v[i]>st.top()){
                    
                st.pop();
                count++;
                    
                    
                    
            }
            if(st.size()!=0){
                count++;
                        
            };
            st.push(v[i]);
            a.push_back(count);
        }
            

        
        reverse(a.begin(),a.end());
        return a;
    }
};