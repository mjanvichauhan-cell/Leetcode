//Push efficient 
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {   }
    void push(int x) {
        this->st1.push(x);
    }
    
    int pop() {
        if(this->st1.empty()) return -1;
        while(this->st1.size()>1){
            this->st2.push(st1.top());
            this->st1.pop();
        }
        int res = st1.top();
        this->st1.pop();
        while(!st2.empty()){
            this->st1.push(st2.top());
            st2.pop();
        }
        return res;
    }
    
    int peek() {
        if(this->st1.empty()) return-1;
        while(this->st1.size()>1){
            st2.push(st1.top());
            st1.pop();
        }
        int res=this->st1.top();
        while(!st2.empty()){
            this->st1.push(st2.top());
            st2.pop();
        }
        return res;
    }
    
    bool empty() {
       return this->st1.empty(); 
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

 //Pop efficient
 class MyQueue {
    stack<int> temp;
    stack<int> st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!this->st.empty()){
            temp.push(this->st.top());
            this->st.pop();
        }
        this-> st.push(x);
        while(!temp.empty()){
            this->st.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
       if(this->st.empty()) return -1 ;
        int res=this-> st.top(); 
        this->st.pop();
        return res;
    }
    
    int peek() {
        if(this->st.empty()) return-1;
        return this->st.top();
    }
    
    bool empty() {
        return this->st.empty();
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