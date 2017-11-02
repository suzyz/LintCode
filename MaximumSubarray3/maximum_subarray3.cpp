class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> &nums, int k) {
    	int n = nums.size();
    	if (n<k)
    		return 0;
    	int f[k+2], g[k+2], ans = INT_MIN;

    	f[0] = g[0] = 0;
    	for (int j = k; j > 0; --j)
    		f[j] = g[j] = INT_MIN;

    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = min(k,i+1); j > 0; --j)
    		{
    			f[j] = max(f[j],g[j-1]) + nums[i];
    			g[j] = max(g[j],f[j]);
    		}
    		if (i+1>=k)
    			ans = f[k] > ans ? f[k]:ans;
    	}
    		
    	return ans;
    }
};
