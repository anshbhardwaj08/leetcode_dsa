class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        int n=a.size();
        int count=0;
        sort(a.begin(),a.end());
        long long total=0;
        total+=mass;
        for(int i=0;i<n;i++){
            if(total>=a[i]){
                total+=a[i];
                count++;
            }
            else{
                break;
            }
        }
        if(count!=n){
            return false;
        }
        return true;
    }
};