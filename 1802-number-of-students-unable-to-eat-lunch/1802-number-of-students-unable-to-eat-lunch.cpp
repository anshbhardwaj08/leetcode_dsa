class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        reverse(sandwiches.begin(),sandwiches.end());
        queue<int>q;
        stack<int>st;
        int i=0;
        while(i<students.size()){
            q.push(students[i]);
            i++;
        }
        int j=0;
        while(j<sandwiches.size()){
            st.push(sandwiches[j]);
            j++;
        }
        int n=q.size();

        int count=0;
        while(q.size()!=0 && count!=n){
            
            
            if(q.front()==st.top()){
                count=0;
                q.pop();

                st.pop();
                
            }
            else{
                count++;
                int x=q.front();
                q.pop();
                q.push(x);
            }
            
        }
        return q.size();

    }
};