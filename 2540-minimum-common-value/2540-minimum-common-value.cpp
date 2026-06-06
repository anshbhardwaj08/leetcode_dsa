class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // int value=-1;
        unordered_map<int,int>mp;
        unordered_set<int>s1;
        unordered_set<int>s2;
        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        
        }
        for(int i=0;i<nums2.size();i++){
            s2.insert(nums2[i]);
            
        }
        for(int j: s1){
            mp[j]++;
        }
        for(int j: s2){
            mp[j]++;
        }
        int mini=INT_MAX;
        for(auto a: mp){
            if(a.second>=2){
                mini=min(a.first,mini);
            }
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;

        
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         if(nums1[i]==nums2[j]){
        //             value=nums1[i];
        //             break;
        //         }
        //     }
        //     if(value!=-1){
        //         break;
        //     }
        // }

        
    }
};