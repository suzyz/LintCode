class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two substrings
     */
    int maxDiffSubArrays(vector<int> &nums) {
    	int n = nums.size();
    	int f[n+2][2],g[n+2][2];
    	f[0][0] = g[0][0] = INT_MIN;
    	f[0][1] = g[0][1] = INT_MAX;

    	int sum = 0, min_sum = 0, max_sum = 0, ans = 0;
    	for (int i = 1; i <= n; ++i)
    	{
    		sum += nums[i-1];
    		f[i][0] = max(f[i-1][0],sum - min_sum);
    		f[i][1] = min(f[i-1][1],sum - max_sum);

    		min_sum = min(sum,min_sum);
    		max_sum = max(sum,max_sum);

    		g[i][0] = max(g[i-1][0], -f[i-1][1]) + nums[i-1];
    		g[i][1] = min(g[i-1][1], -f[i-1][0]) + nums[i-1];

    		if (i>1)
    		{
    			ans = max(abs(g[i][0]), ans);
    			ans = max(abs(g[i][1]), ans);
    		}
    	}
    	return ans;
    }
};
