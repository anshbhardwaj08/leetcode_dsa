class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for( int ele: arr){
            int a=ele;
            int dist=abs(a-x);
            pq.push({dist,a});
            if(pq.size()>k){
                pq.pop();

            }
        }
        while(pq.size()>0){
            int d=pq.top().second;
            pq.pop();
            
            ans.push_back(d);
            

        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};