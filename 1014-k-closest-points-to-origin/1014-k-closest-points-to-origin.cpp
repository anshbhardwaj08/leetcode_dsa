class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        typedef pair<int,vector<int>>pi;
        priority_queue<pi>pq;
        vector<vector<int>>ans;
        for(auto& x: points ){
            
            int b=x[1];
            int a=x[0];
            int dist=abs((a*a)+(b*b));
            pq.push({dist,x});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()>0){
            vector<int>res=pq.top().second;
            ans.push_back(res);
            pq.pop();
        }
        return ans;
    }
};