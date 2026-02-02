class Solution {
public:
    typedef long long ll;
    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        //Stores (k-1) min el
        set<pair<ll , ll>>kMin;
        set<pair<ll , ll>>remaining;
        //stores sum of (k-1) min el
        ll sum =0;

        int i =1;

        while(i- dist < 1){
            kMin.insert({nums[i] , i});
            sum += nums[i];
            //Remove the largest el
            if(kMin.size() > k-1){
                pair<ll, ll> temp = *kMin.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMin.erase(temp);
            }
            i++;
        }
//Stores min sum of (k-1) el
        ll res = LONG_MAX;
        while(i < n){
            kMin.insert({nums[i] , i});
            sum += nums[i];
            if(kMin.size() > k-1){
                pair<ll, ll> temp = *kMin.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMin.erase(temp);
            }
            res = min(res , sum);

            //Shift window
            //(i-dist) el will be removed
            pair<ll , ll>remove = {nums[i-dist] , i-dist};
            if(kMin.count(remove)){
                kMin.erase(remove);
                sum-=remove.first;

                if(!remaining.empty()){
                    pair<ll,ll> temp = *remaining.begin();
                    kMin.insert(temp);
                    sum += temp.first;
                    remaining.erase(temp);

                }
                
            }else{
                    remaining.erase(remove);
                }
                i++;

        }
        return nums[0] + res;

    }
};