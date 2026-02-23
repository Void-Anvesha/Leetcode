class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        //No of substr poss = 2^k
        int cnt = pow(2 , k); 
        int n = s.length();

        for(int i = k; i <= n; i++){

            string sub = s.substr(i - k , k);
            if(!st.count(sub)){
                st.insert(sub);
                cnt--;
            }
            if(cnt == 0)return true;
        }
    return false;
    }
};