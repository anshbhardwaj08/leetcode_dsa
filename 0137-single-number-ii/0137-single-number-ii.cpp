class Solution {
public:
    int singleNumber(vector<int>& nums) {
        typedef pair<int,int>p;
        unordered_map<int ,int>m;
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int ele:nums){
            m[ele]++;
        }
        for(auto x:m){
            int freq=x.second;
            int n=x.first;
            pq.push({freq,n});
        }
        return pq.top().second;
    }
};