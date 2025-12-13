class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        //Map containg all the businessLine values
        //Also corresponding priority for sorting
        unordered_map<string,int>priority={
        {"electronics",0},
        {"grocery",1},
        {"pharmacy",2},
        {"restaurant",3}
        };
        //(business priority,code)
        vector<pair<int,string>>valid;
        for(int i=0; i<code.size(); i++){
            //Check active
            if(!isActive[i])continue;

            //Check business line
            if(priority.find(businessLine[i])==priority.end())continue;


            //Cheeck code validity
            if(code[i].empty())continue;
            bool ok=true;
            for(char c:code[i]){
                if(!isalnum(c) && c!='_'){
                    ok=false;
                    break;
                }
            }
            if(!ok)continue;
            valid.push_back({priority[businessLine[i]],code[i]});
        }
       //Sort by businessLine priority
       // If businessLine are same then lexicographically by code
       sort(valid.begin(),valid.end(),[](auto&a,auto&b){
        if(a.first!=b.first)
           return a.first<b.first;
        return a.second<b.second;
       });

       //Extract only codes in res
       vector<string>result;
       for(auto& p:valid){
        result.push_back(p.second);
       }
     return result;
    }
};