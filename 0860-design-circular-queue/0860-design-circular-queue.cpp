class MyCircularQueue {
public:
    int f;
    int b;
    int s;
    int c;
    vector<int>arr;
    MyCircularQueue(int k) {
        f=0;
        b=0;
        s=0;
        c=k;
        vector<int>v(k);
        arr=v;

    }
    
    bool enQueue(int value) {
        if(s==c) return false;
        arr[b]=value;
        b++;
        if(b==c) b=0;
        s++;
        return true;
    }
    
    bool deQueue() {
        if(s==0) return false;
        arr.pop_back();
        f++;
        if(f==c) f=0;

        s--;
        return true;

    }
    
    int Front() {
       if(s==0) return -1;
       return arr[f]; 
    }
    
    int Rear() {
        if(s==0) return -1;
        if(b==0) return arr[c-1];
        return arr[b-1];
    }
    
    bool isEmpty() {
        if(s==0) return true;
        return false;
    }
    
    bool isFull() {
        if(s==c) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */