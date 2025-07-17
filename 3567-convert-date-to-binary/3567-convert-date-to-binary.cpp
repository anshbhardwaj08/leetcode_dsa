class Solution {
public:
    void dtb(int &a, string &h){
    if(a==1){
        h=h+to_string(1);
        return ;
    }
    
    int x=a%2;
    a=a/2;
    string y=to_string(x);
    dtb(a,h);
    h=h+y;
    
    }

    string convertDateToBinary(string date) {
        string first;
        string second;
        string third ;
        for(int i=0;i<=3;i++){
            first.push_back(date[i]);
        }
        for(int i=5;i<=6;i++){
            second.push_back(date[i]);
        }
        for(int i=8;i<=9;i++){
            third.push_back(date[i]);
        }

        string f="";
        int b=stoi(first);
        dtb(b,f);

        string s="";
        int c=stoi(second);
        dtb(c,s);

        string t="";
        int d=stoi(third);
        dtb(d,t);
        string a=f+"-"+s+"-"+t;
        return a;
        
    }
};