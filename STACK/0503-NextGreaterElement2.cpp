class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
    int n=arr.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for (int i=2*n-1;i>=0;i--){
        while(!st.empty() and arr[i%n]>=arr[st.top()]){
            st.pop();
        }
        output[i%n]=st.empty()?-1:arr[st.top()];
        st.push(i%n);
    }
    return output;
    }
    
};