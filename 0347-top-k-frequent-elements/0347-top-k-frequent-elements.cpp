class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int>pi;
        unordered_map<int,int>m;
        vector<int>v;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(int ele: nums){
            m[ele]++;
        }// in map we have stored {ele,freq}
        for(auto x: m){
            int ele=x.first;
            int freq=x.second;
            pair<int,int>a={freq,ele};
            pq.push(a);
            if(pq.size()>k){
                pq.pop();
            }
        }

        while(pq.size()>0){
            int ans=pq.top().second;
            pq.pop();
            v.push_back(ans);
        }
        return v;

        
    }
};