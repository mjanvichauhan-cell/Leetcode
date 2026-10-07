class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    vector<int> left(n,0);
    vector<int> right(n,0);
    stack<int> st;
    int ans=0;
    for (int i=n-1;i>=0;i--){
        while(st.size()>0 and heights[i]<= heights[st.top()]){
            st.pop();
        }
        right[i]=st.empty()?n:st.top();
        st.push(i);
    }
    while(not st.empty()){
        st.pop();
    }
    for (int i=0;i<n;i++){
        while(st.size()>0 and heights[i]<= heights[st.top()]){
            st.pop();
        }
        left[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    for(int i=0;i<n;i++){
        int width=right[i]-left[i]-1;
        int currarea=heights[i]*width;
        ans=max(ans,currarea);
    }
    return ans;
    
    }
};