class MyStack {
public:
int n;
   queue<int> q1;
   queue<int> q2;
    MyStack() {
         n=0;
    }
    
    void push(int val) {
         q2.push(val);
      n++;
      while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
      }
      queue<int> temp=q1;
      q1=q2;
      q2=temp;
    }
    
    int pop() {
        int ans=q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
