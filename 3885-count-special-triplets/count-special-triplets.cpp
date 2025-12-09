class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        const long long MOD=1'000'000'007;
        //<el,cnt>
        map<long,long>left;
        map<long,long>right;
        long long cnt=0;

        for(int i=2;i<n;i++) right[nums[i]]++;
        left[nums[0]]++;

        for(int i=1;i<n-1;i++){
            long long req=nums[i]*2LL;
            if(left.count(req) && right.count(req)){
               cnt=(cnt+(left[req]*right[req])%MOD)%MOD;
            }
            right[nums[i+1]]--;
            //If the cnt of an el is 0 (Remove it)
            if(right[nums[i+1]]==0) right.erase(nums[i+1]);
            left[nums[i]]++;
        }
        return (int)cnt%MOD;
    }
};