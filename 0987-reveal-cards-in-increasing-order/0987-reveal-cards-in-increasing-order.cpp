class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(),deck.end());
        vector<int>ans(n);
        queue<int>q;
        int i=0;
        while(i<n){
            q.push(i);
            i++;
        }
        int j=0;
        while(j<n && q.size()!=0){
            int idx;
            idx=q.front();
           
            q.pop();
            q.push(q.front());
            q.pop();
            ans[idx]=deck[j];
            j++;
        }

        return ans;


    }
};