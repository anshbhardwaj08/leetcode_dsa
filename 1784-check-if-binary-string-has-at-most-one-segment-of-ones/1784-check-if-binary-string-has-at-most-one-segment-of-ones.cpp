class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        // int z=0;
        // int one=0;
        
        // int i=0;
        // while(i<s.size()){
        //     if(s[i]=='1'){
        //         int j=i;
        //         int count=0;
        //         while(s[j]=='1'){
        //             count++;
        //             j++;
        //         }
        //         one=max(one,count);
        //         i=j;
        //     }
        //     else{
        //         int k=i;
        //         int c=0;
        //         while(s[k]=='0'){
        //             c++;
        //             k++;
        //         }
        //         z=max(z,c);
        //         i=k;
        //     }
        // }
        bool flag=true;
        int i=0;
        while(s[i]=='1'){
            // if(s[i-1]=='0'){
            //     flag=false;
            //     break;
            // }
            i++;
        }
        while(i<n){
            if(s[i]=='1'){
                flag=false;
            }
            i++;
        }
        return flag;

    }
};