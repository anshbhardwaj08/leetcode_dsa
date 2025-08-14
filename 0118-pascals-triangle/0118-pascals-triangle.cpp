class Solution {
public:
    // long double fact(long double a){
    //     int i=2; 
    //     long double b=1;
    //     if(a==0 || a==1) return 1;
    //     while(i<=a){
    //         b=b*i;
    //         i++;
    //     } 

    //     return b;

    // }
    // int nCr(int h, int x){
    //     long double c=fact(h);
    //     long double m=(fact(h-x)*fact(x));

    //     return static_cast<int>(c / m);
    // }
    int nCr(int n, int r) {
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
        }
        return static_cast<int>(res);
    }
    vector<vector<int>> generate(int k) {
        vector<vector<int>> ans;
        if(k==1){
            vector<int>q;
            q.push_back(1);
            ans.push_back(q);
            return ans;
        }
        for(int i=0; i<k ;i++){
            vector<int>v;
            for(int j=0;j<=i;j++){
                
                v.push_back(nCr(i,j));
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};