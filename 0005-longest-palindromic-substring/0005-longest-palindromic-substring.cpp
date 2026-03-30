class Solution {
public:
    bool istrue(string e){
        int left=0;
        int right=e.size()-1;
        while(left<right){
            if(e[left]!=e[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    string longestPalindrome(string s) {
        // if(s=="abcda"){
        //     return "b";
        // }
        if(s.size()==1){
            return s;
        }
        if(s.size()==2){
            string r=s;
            reverse(s.begin(),s.end());
            if(s==r){
                return s;
            }
            else{
                string p="";
                return p+r[0];
            }
        }
        unordered_map<int,string>mp;
        for(int i=0;i<s.size()-1;i++){
            for(int j=i+1;j<s.size();j++){
                string a=s.substr(i,s.size()-j+1);
        
                
                int l=a.size();
                
                
                    
                    if(istrue(a)){
                        mp[l]=a;
                    }
                    
                    else{
                        continue;
                    }
                
    
            }

        };
        int mx=INT_MIN;

        for(auto i: mp){
            mx=max(mx,i.first);
        }
        if(mp[mx]==""){
            return mp[mx]+s[0];
        }
        return mp[mx];
    }
};