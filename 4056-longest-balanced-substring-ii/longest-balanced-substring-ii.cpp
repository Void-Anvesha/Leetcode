class Solution {
public:
    int helper(string& s ,int ch1 , int ch2){
        int n = s.length();
        unordered_map<int, int>diffMap;
        int cnt1 = 0 , cnt2 =0;
        int maxL = 0;

        for(int i = 0; i < n; i++){
            if(s[i] != ch1 && s[i] != ch2){
                diffMap.clear();
                cnt1 = 0;
                cnt2 = 0;
                continue;
            }

            if(s[i] == ch1)cnt1++;
            if(s[i] == ch2)cnt2++; 
            if(cnt1 == cnt2)maxL = max(maxL ,cnt1 + cnt2);

            int diff = cnt1 - cnt2;
            if(diffMap.count(diff)){
                maxL = max(maxL , i - diffMap[diff]);
            }else{
                diffMap[diff] = i;
            }
        }
        return maxL;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int maxL = 0;


        //Case 1
        //"aaaa"
        int cnt = 1;//s[0]
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1])cnt++;
            else {
                maxL = max(maxL , cnt);
                cnt = 1;

            }
        }
        maxL = max(maxL , cnt);

        //Case 2
        maxL = max(maxL , helper(s , 'a'  , 'b'));
        maxL = max(maxL , helper(s , 'a'  , 'c'));
        maxL = max(maxL , helper(s , 'b'  , 'c'));

        //Case -3
        int cntA = 0;
        int cntB = 0;
        int cntC = 0;
        unordered_map<string,int>diffMap;

        for(int i =0; i < n; i++){
            if(s[i] == 'a')cntA++;
            if(s[i] == 'b')cntB++;
            if(s[i] == 'c')cntC++;

            if(cntA == cntB && cntA == cntC) maxL = max(maxL , cntA+cntB+cntC);

            int diffAB = cntA - cntB;
            int diffAC = cntA - cntC;
            
            string key = to_string(diffAB) + "_" + to_string(diffAC);

            if(diffMap.count(key)){
                maxL = max(maxL , i - diffMap[key]);
            }else{
                diffMap[key] = i;
            }

        }

    return maxL;

    }
};