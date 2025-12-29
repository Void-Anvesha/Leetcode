class Solution {
public:
    //Memoization
    unordered_map<string,bool>t;

    bool solve(string curr , unordered_map<string , vector<char>>&mp , int idx , 
               string above){
            //Pyramid is found & we are at the top
             if(curr.length()==1) return true;

             //Creating key(Memoization)
             string key = curr + "_" + to_string(idx) + "_" + above;

             if(t.count(key))return t[key];
             
            //Time to move to above row
            //Finished curr string
             if(idx == curr.length()-1) return t[key]=solve(above , mp , 0 , "");

             string pair = curr.substr(idx,2);
             if(mp.find(pair) == mp.end())return t[key]=false;

             //Iterate through all possible char of a pair
             for(char& ch: mp[pair]){
                above.push_back(ch);//DO

                if(solve(curr,mp,idx+1,above) == true)return t[key]=true;//EXPLORE

                above.pop_back();//UNDO
             }
             return t[key]=false;

        }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>>mp;

        for(auto& pattern : allowed){
            //"ABC"
            //AB : C
            mp[pattern.substr(0,2)].push_back(pattern[2]);
        }

        return solve(bottom , mp , 0 , "");
    }
};