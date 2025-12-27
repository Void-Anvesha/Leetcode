class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        if(k == 0)return nums;
        int n=nums.size();
        vector<int>result(n , -1);

        if(n < 2*k+1) return result;

        long long window= 0;
        int left =0;
        int right = 2 * k;
        int i=k;

        for(int i=left; i<=right; i++){
            window += nums[i];
        }

        result[i] = window/(2 * k +1);
        i++;
        right++;


        while(right < n){

            int out_of_window = nums[left];
            int came_to_window = nums[right];

            window = window + came_to_window - out_of_window;

            result[i] = window/(2 * k +1);

            i++;
            right++;
            left++;
        }
        return result;


    }
};