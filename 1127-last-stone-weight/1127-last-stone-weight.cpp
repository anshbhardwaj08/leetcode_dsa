class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        // sort(stones.begin(),stones.end());
        // reverse(stones.begin(),stones.end());
        for(int ele: stones ){
            pq.push(ele);
        }
        int n=pq.size();
        while(pq.size()!=1){
            int a = pq.top();
            pq.pop();
            int b=pq.top();
            int diff=a-b;
            if(diff==0 && pq.size()==1 ){
                return 0;
            }
            if(diff==0) {
                pq.pop();

            }
            else if(diff!=0){
                pq.pop();
                pq.push(diff);
            }

        }
        return pq.top();
    }
};