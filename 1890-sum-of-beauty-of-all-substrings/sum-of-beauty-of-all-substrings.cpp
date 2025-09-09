class Solution {
public:
   int getMaxCnt(map<char,int>&mp)
   {
     int maxi=0;
      for(auto it:mp)
      {   int val=it.second;
          maxi=max(maxi,val);
      }
      return maxi;
   }

   int getMinCnt(map<char,int> &mp){
    int mini=INT_MAX;
    for(auto it:mp)
      {   int val=it.second;
          mini=min(mini,val);
      }
      return mini;
    
   }
    int beautySum(string s) {
        int sumOfBeauty=0;
        for(int i=0;i<s.length();i++)
        { 
            map<char,int>mp;
            for(int j=i;j<s.length();j++)
            {
                mp[s[j]]++;
                int beauty=getMaxCnt(mp)-getMinCnt(mp);
                sumOfBeauty+=beauty;
            }

        }
        return sumOfBeauty;
    }
};