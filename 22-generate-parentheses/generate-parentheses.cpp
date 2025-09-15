class Solution {
public:
    void findValidParanthesis(int open, int close, string curr, vector<string> &result) {
        if(open == 0 && close == 0){
            result.push_back(curr);
            return;
        }
        if(open > 0)
            findValidParanthesis(open - 1, close, curr + '(', result);
        if(close > open)
            findValidParanthesis(open, close - 1, curr + ')', result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        findValidParanthesis(n, n, "", result);
        return result;
    }
};
