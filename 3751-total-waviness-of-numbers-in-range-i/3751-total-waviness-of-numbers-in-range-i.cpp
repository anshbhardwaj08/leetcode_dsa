class Solution {
public:
    int solve(int n){
        int count=0;
        vector<int>v;
        while(n!=0){
            int a=n%10;
            v.push_back(a);
            n=n/10;
        }
        reverse(v.begin(),v.end());
        for(int i=1;i<v.size()-1;i++){
            if(v[i]>v[i-1] && v[i]>v[i+1]){
                count++;
            }
            else if(v[i]<v[i-1] && v[i]<v[i+1]){
                count++;
            }
            else{
                continue;
            }
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int t=0;
        for(int n=num1;n<=num2;n++){
            int ans=solve(n);
            t+=ans;
        }
        return t;
    }
};