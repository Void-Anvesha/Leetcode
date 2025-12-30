class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();

        int i=0, j=0;
        int res=0;
        unordered_map<char,int>mp;

        while(j < n){
            mp[answerKey[j]]++;

            while(min(mp['T'] , mp['F']) > k){
                mp[answerKey[i]]--;
                i++;
            }
            res= max(res , j-i+1);
            j++;
        }
        return res;
    }
};