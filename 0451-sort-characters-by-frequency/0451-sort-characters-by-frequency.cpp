class Solution {
public:
    string frequencySort(string s) {
        typedef pair<int ,char>pi;
        priority_queue<pi>pq;
        unordered_map<char ,int>m;
        for(char a: s){
            
            m[a]++;
        }
        for(auto &x : m){
           
            char c=x.first;
            int freq=x.second;
            pq.push({freq,c});
        }
        string ans="";
        while(pq.size()!=0){
            int n=pq.top().first;
            char m=pq.top().second;
            // ans.append(n,m);
            // pq.pop();
            while(n!=0){
                ans+=m;
                n--;
                
            }
            if(n==0) pq.pop();
            
        }
        return ans;

    }
};