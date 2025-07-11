
class MyQueue {
public:
    stack<int>st;
    stack<int>h;
    MyQueue() {
       

        
    }
    
    void push(int x) {
        st.push(x);
        
    }
    
    int pop() {
        while(st.size()!=0){
            int x=st.top();
            st.pop();
            h.push(x);
        }
        int y=h.top();
        h.pop();
        while(h.size()!=0){
            int x=h.top();
            h.pop();
            st.push(x);
        }
        return y;

        
    }
    
    int peek() {
        while(st.size()!=0){
            int x=st.top();
            st.pop();
            h.push(x);
        }
        int y=h.top();
        
        while(h.size()!=0){
            int x=h.top();
            h.pop();
            st.push(x);
        }
        return y;

        
    }
    
    bool empty() {
        if(st.size()==0) return true;
        return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */