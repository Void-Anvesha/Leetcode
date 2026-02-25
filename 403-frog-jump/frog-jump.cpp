class Solution {
public:
    int n;
    unordered_map<int,int>mp;
    int t[2001][2001];
    bool solve(vector<int>& stones , int curr_stone_idx , int prevJump){
        //Reached end
       if(curr_stone_idx == n-1)return true;

       if(t[curr_stone_idx][prevJump] != -1)return t[curr_stone_idx][prevJump];

       bool res = false;
       //There are 3 poss from each index (prevJump-1 , prevJump , prevJump+1)
       for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++ ){

           if(nextJump > 0){
              int next_stone = stones[curr_stone_idx] + nextJump;
              //Stone present in  mp
              if(mp.find(next_stone) != mp.end()){
                 res = res || solve(stones ,mp[next_stone] , nextJump);
              }
           }
       }
    return t[curr_stone_idx][prevJump] = res;
    }


    bool canCross(vector<int>& stones) {
        n = stones.size();
       //1st jump can be of only 1 unit
        if(stones[1] != 1){
            return false;
        }
    
     //{stone , idx of stone}
        for(int i = 0; i < n; i++){
           mp[stones[i]] = i; 
        }
        memset(t , -1 , sizeof(t));
        return solve(stones , mp[0] , 0);

    }
};