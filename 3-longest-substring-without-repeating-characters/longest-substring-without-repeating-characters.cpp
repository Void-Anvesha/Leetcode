class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_map<char , int>mp;
        int l =0 , r=0;

        for(int r =0; r < s.length(); r++){
             char c = s[r];

             if(mp.find(c)!= mp.end() && mp[c]>= l){
                l = mp[c] + 1;
             }
             mp[c] = r;
             longest = max(longest , r -l +1);
        }
        return longest;
    }
};