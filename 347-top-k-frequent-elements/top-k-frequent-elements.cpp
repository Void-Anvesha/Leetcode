class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;

    for(auto& it:mp)
    {  //{freq,el}
        p.push({it.second,it.first});

        if(p.size()>k) p.pop();
    }

     //Pushing the el with highest freq in resullt
     while(!p.empty())
     {
        result.push_back(p.top().second);
        p.pop();
     }
     return result;

    }
};