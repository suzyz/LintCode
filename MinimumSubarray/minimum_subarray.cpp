class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    int minSubArray(vector<int> &nums) {
        int n = nums.size();
        if (n==0)
            return 0;
        int sum = 0,max_sum = 0, ans = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            ans = min(ans,sum - max_sum);

            max_sum = max(max_sum,sum);
        }

        return ans;
    }
};
