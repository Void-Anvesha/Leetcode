class Solution {
public:
    int beautySum(string s) {
        int sumOfBeauty=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp.clear();
            for(int j=i;j<s.size();j++)
            {
                mp[s[j]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto& it:mp){
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                int beauty=maxi-mini;
                sumOfBeauty+=beauty;
            }
        }
        return sumOfBeauty;
    }
};