class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        int n = nums.size();
        if (n<2)
        	return 0;

        int f[2], g[2], sum = 0, min_sum = 0, ans = INT_MIN;
        f[0] = g[0] = INT_MIN/2;
        int flag = 1;
        for (int i = 1; i <= n; ++i)
        {
        	sum += nums[i-1];
        	f[flag] = max(f[1-flag],sum - min_sum);

        	min_sum = min(min_sum,sum);

        	g[flag] = max(g[1-flag],f[1-flag]) + nums[i-1];
        	ans = max(ans,g[flag]);

            flag = 1-flag;
        }

        return ans;
    }
};
