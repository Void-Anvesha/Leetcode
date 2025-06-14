class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n + 1, 0); 

        for (auto v : trust) {
            degree[v[0]]--; // person v[0] trusts someone → lose trust score
            degree[v[1]]++; // person v[1] is trusted → gain trust score
        }

        for (int i = 1; i <= n; i++) {
            if (degree[i] == n - 1) {
                return i; 
            }
        }

        return -1; 
    }
};
