class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int len = s.length();
        int ans = 0;
        int currNo = 0;
        int sign = 1;

        for (int i = 0; i < len; i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                currNo = currNo * 10 + (ch - '0');
            }
            else if (ch == '+') {
                ans += currNo * sign;
                currNo = 0;
                sign = 1;
            }
            else if (ch == '-') {
                ans += currNo * sign;
                currNo = 0;
                sign = -1;
            }
            else if (ch == '(') {
                st.push(ans);    // Save current result
                st.push(sign);   // Save current sign
                ans = 0;
                sign = 1;
            }
            else if (ch == ')') {
                ans += currNo * sign;
                currNo = 0;
                ans *= st.top(); st.pop();  // sign before '('
                ans += st.top(); st.pop();  // result before '('
            }
            // Ignore spaces
        }

        ans += currNo * sign;  // Add any remaining number
        return ans;
    }
};
