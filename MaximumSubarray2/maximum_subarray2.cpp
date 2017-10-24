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

        int f[n+2], g[n+2], sum = 0, min_sum = 0, ans = INT_MIN;
        f[0] = g[0] = INT_MIN/2;
        for (int i = 1; i <= n; ++i)
        {
        	sum += nums[i-1];
        	f[i] = max(f[i-1],sum - min_sum);

        	min_sum = min(min_sum,sum);

        	g[i] = max(g[i-1],f[i-1]) + nums[i-1];
        	ans = max(ans,g[i]);
        }

        return  ans;
    }
};
