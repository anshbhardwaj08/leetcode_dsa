class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int i = 0; // players
        int j = 0; // trainers
        int count = 0;
        
        while(i < players.size() && j < trainers.size()) {
            if(trainers[j] >= players[i]) {
                // match found
                count++;
                i++;
                j++;
            } else {
                // trainer too weak → try next trainer
                j++;
            }
        }
        
        return count;
    }
};