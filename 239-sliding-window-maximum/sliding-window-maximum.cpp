class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi;
        deque<int> dq;

        // First window
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Store max of first window
        maxi.push_back(nums[dq.front()]);

        // Process the rest
        for (int i = k; i < n; i++) {
            // Remove indices out of the window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Store current max
            maxi.push_back(nums[dq.front()]);
        }

        return maxi;
    }
};
