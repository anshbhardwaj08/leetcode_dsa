class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>a;
        vector<int>b;
        for(int i=prices.size()-1;i>=0;i--){
            b.push_back(prices[i]);
        }
        sort(prices.begin(),prices.end());
        for(int i=0;i<prices.size();i++){
            a.push_back(prices[i]);
        }
        if(a==b) return 0;
        vector<int>c;
        for(int i=b.size()-1;i>=0;i--){
            c.push_back(b[i]);

        }
        stack<int>st;
        

        int diff=0;
        st.push(c[0]);

        for(int i=1;i<c.size();i++){
            int d=0;
            
            if(c[i]<st.top() ){
                st.pop();
                st.push(c[i]);

            }
            else{
                d=c[i]-st.top();

            }
            diff=max(d,diff);
            


            
        }
        return diff;

    }
};