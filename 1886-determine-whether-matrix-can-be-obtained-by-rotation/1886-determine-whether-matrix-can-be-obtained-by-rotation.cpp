class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int ones=0;
        int zeroes=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    ones++;
                }
                else{
                    zeroes++;
                }
            }
        }
        int one=0;
        int zero=0;
        for(int i=0;i<target.size();i++){
            for(int j=0;j<target[0].size();j++){
                if(target[i][j]==0){
                    zero++;
                }
                else{
                    one++;
                }
            }
        }
        if(zero!=zeroes || one!=ones){
            return false;
        }
        bool flag=false;
        
            for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                    if(mat[i][j]==target[i][j]){
                        flag=true;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag==false){
                    break;
                }
            }
        
        if(flag==true){
            return true;
        }
        // for(int i=0;i<mat.size();i++){
        //         for(int j=0;j<mat[0].size();j++){
        //             if(mat[j][i]==target[i][j]){
        //                 flag=true;
        //             }
        //             else{
        //                 flag=false;
        //                 break;
        //             }
        //         }
        //         if(flag==false){
        //             break;
        //         }
        //     }
        //     if(flag==true){
        //         return true;
        //     }
            
            for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                    if(mat[mat.size()-1-j][i]==target[i][j]){
                        flag=true;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag==false){
                    break;
                }
            }
            if(flag==true){
                return true;
            }

            for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                    if(mat[mat.size()-1-i][mat[0].size()-1-j]==target[i][j]){
                        flag=true;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag==false){
                    break;
                }
            }
            if(flag==true){
                return true;
            }
            for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                    if(mat[j][mat[0].size()-1-i]==target[i][j]){
                        flag=true;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag==false){
                    break;
                }
            }
            
            return flag;
        
    }
};