class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int rcount=0;
        int lcount=0;
        int count=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='R'){
                rcount++;
            }
            else if(moves[i]=='L'){
                lcount++;
            }
            else{
                count++;
            }
        }
        return count+abs(lcount-rcount);
    }
};