class Solution {
public:
    string predictPartyVictory(string str) {
        queue<int>q;
        queue<int>r;
        queue<int>d;
        int i=0;
        while(i<str.size()){
            q.push(i);
            if(str[i]=='R'){
                r.push(i);
            }
            if(str[i]=='D'){
                d.push(i);
            }
            i++;
        }
        if(d.size()==0 && r.size()!=0){
            return "Radiant";
        }
        if(r.size()==0 && d.size()!=0){
            return "Dire";
        }

        while(q.size()>1){
            if(d.size()==0 || r.size()==0) break;
            if(str[q.front()]=='X'){
                q.pop();
            }
            if(str[q.front()]=='R' && d.size()!=0){
                int x=q.front();
                q.pop();
                q.push(x);
                int y=r.front();
                r.pop();
                r.push(y);
                str[d.front()]='X';
                d.pop();
            }

            if(str[q.front()]=='D' && r.size()!=0){
                int x=q.front();
                q.pop();
                q.push(x);
                int y=d.front();
                d.pop();
                d.push(y);
                str[r.front()]='X';
                r.pop();
            }
        }
        if(r.size()>0){
            return "Radiant";
        }
        return "Dire";


    }
};