class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
    	int n = nums.size();
    	if (n == 0)
    		return 0;
    	int min_sum = nums[0] < 0 ? nums[0]:0, sum = nums[0], ans = nums[0];
    	for (int i = 1; i < n; ++i)
    	{
    		sum += nums[i];
    		
    		if (sum - min_sum > ans)
    			ans = sum - min_sum;

    		if (sum < min_sum)
    			min_sum = sum;
    	}
    	return ans;
    }
};
