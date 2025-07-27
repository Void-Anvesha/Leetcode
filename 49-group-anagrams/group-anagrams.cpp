class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //Map : Keys->strings & val->vector of strings
        unordered_map<string,vector<string>> anagramMap;

         for (string s:strs)
         {
            string key=s;
            sort(key.begin(),key.end());
            anagramMap[key].push_back(s);
         }

         vector<vector<string>>ans;
         for(auto&temp:anagramMap)
         {
            ans.push_back(temp.second);
         }
          return ans;
    }
   
};