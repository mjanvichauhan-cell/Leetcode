class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> leftMin(n), rightMin(n);
        vector<int> leftMax(n), rightMax(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            leftMin[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            rightMin[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            leftMax[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            rightMax[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            long long maxContribution = 1LL * nums[i] * leftMax[i] * rightMax[i];
            long long minContribution = 1LL * nums[i] * leftMin[i] * rightMin[i];
            ans += maxContribution - minContribution;
        }
        return ans;
    }
};