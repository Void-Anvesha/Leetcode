#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> mapping = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        string current;
        helper(digits, 0, mapping, current, result);
        return result;
    }
private:
    void helper(const string& digits, int i, const vector<string>& mapping, string& current, vector<string>& result) {
        if (i == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[i] - '2'];
        for (char c : letters) {
            current.push_back(c);
            helper(digits, i + 1, mapping, current, result);
            current.pop_back();
        }
    }
};
