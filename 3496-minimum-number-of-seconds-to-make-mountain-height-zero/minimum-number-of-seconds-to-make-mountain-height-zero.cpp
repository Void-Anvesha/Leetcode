class Solution {
public:
    typedef long long ll;

    bool Check(ll mid ,  vector<int>& workerTimes , int mountainHeight){
        ll h = 0;

        for(int &t : workerTimes){
            h += (ll)(sqrt(2.0 * mid / t + 0.25)- 0.5);
            if(h >= mountainHeight)return true;
        }
        return h >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(workerTimes.begin() , workerTimes.end());
        ll l = 1;
        ll r =(ll) maxTime*(mountainHeight) *(mountainHeight + 1)/2;

        ll res = 0;

        while(l <= r){

            ll mid = l + (r-l)/2;

            if(Check(mid , workerTimes , mountainHeight)){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
    return res;
    }
};