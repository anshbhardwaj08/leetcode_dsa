class Solution {
public:
    int romanToInt(string s) {
        // int a=0;
        // unordered_map<char,int>m;
        // m=
        // for(int i=s.size()-1;i>=0;i--){
        //     if(s[i]=='I'){
                
        //         a+=1;
        //     }
        //     else if(s[i]=='V'){
        //         if(s[i-1])
        //         a+=5;
        //     }
        //     else if(s[i]=='X'){
        //         a+=10;
        //     }
        //     else if(s[i]=='L'){
        //         a+=50;
        //     }
        //     else if(s[i]=='C'){
        //         a+=100;
        //     }
        //     else if(s[i]=='D'){
        //         a+=500;
        //     }
        //     else{
        //         a+=1000;
        //     }

        // }
        // return a;
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            // If current value is less than the next value, subtract it
            if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } else {
                total += roman[s[i]];
            }
        }
        return total;
        
    }
};