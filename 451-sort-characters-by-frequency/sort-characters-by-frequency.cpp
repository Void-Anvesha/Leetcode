class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char c:s)
        {
            mp[c]++;
        }
    //Max heap to sort by frequency
    priority_queue<pair<int,char>>p;
    for(auto &[character,cnt]:mp)
    {
        p.push({cnt,character});
    }

    string result="";
     while(!p.empty())
     { 
        auto [cnt,character]=p.top();
        p.pop();
        result.append(cnt,character);

     }
    return result;
    }
};