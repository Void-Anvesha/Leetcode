class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            unordered_map<char,int>freq;
            for(int j = i; j < n ; j++){
                freq[s[j]]++;
                
                bool balanced = true;
                int cnt = freq.begin()->second;
                for(auto& [ch , fr] : freq){
                    if(fr != cnt){
                        balanced = false;
                        break;
                    }
                }
                if(balanced) maxLen = max(maxLen , j - i +1);
            }

        }
        return maxLen;
    }
};