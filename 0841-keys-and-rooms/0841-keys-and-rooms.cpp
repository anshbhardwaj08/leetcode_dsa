class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>visited;
        queue<int>q;
        q.push(0);
        visited.insert(0);
        while(q.size()!=0){
            int curr=q.front();
            q.pop();
            for(auto i: rooms[curr]){
                if(!visited.count(i)){
                    visited.insert(i);
                    q.push(i);
                }
            }
        }
        if(visited.size()==rooms.size()) return true;
        return false;
    }
};