class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         priority_queue<int> minHeap;

        // Push all elements into the min-heap
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                minHeap.push(matrix[i][j]);
                if(minHeap.size()>k){
                    minHeap.pop();

                }
            }
        }
        return minHeap.top();
    }
};