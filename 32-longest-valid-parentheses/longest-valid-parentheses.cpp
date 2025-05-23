class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Sentinel to help calculate lengths easily
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (!st.empty()) {
                    maxLength = max(maxLength, i - st.top());
                } else {
                    st.push(i);
                }
            }
        }

        return maxLength;
    }
};
