class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image , sr,sc, image[sr][sc],color);
        return image;
    }
    void dfs(vector<vector<int>>& image, int cr, int cc, int initialcolor,int color){
        int m= image.size();
        int n=image[0].size();
        if(initialcolor==color) return ;
        
        
        if(cc>=n || cr>=m || cr<0 || cc<0){
            return ;
        }
        if(image[cr][cc]!=initialcolor){//this is for different colour 
            return ;
        }
        image[cr][cc]=color;
        dfs(image,cr-1,cc,initialcolor,color);
        dfs(image,cr,cc-1,initialcolor,color);
        dfs(image,cr+1,cc,initialcolor,color);
        dfs(image,cr,cc+1,initialcolor,color);
    }
};