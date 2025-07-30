class FindSumPairs {
public:
    unordered_map<int,int>m;
    vector<int>v1;
    vector<int>v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1=nums1;
        v2=nums2;
        for(auto x:v2){
            m[x]++;
        }

    }
    
    void add(int index, int val) {
        if(index>=v2.size()){
            m[val]++;
            v2.push_back(val);
        }
        m[v2[index]]--;
        v2[index]+=val;
        m[v2[index]]++;
    }
    
    int count(int tot) {
        int ct=0;
        for(int i=0;i<v1.size();i++){
            if(m.find(tot-v1[i])!=m.end()){
                ct+=m[tot-v1[i]];
            }
        }
        return ct;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */