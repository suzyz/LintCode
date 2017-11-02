class Solution {
public:
    /*
     * @param : the given array
     * @return: the minimum difference between their sums 
     */
    int findMin(vector<int> &nums) {
    	int n = nums.size();
    	int sum = 0;

    	for (int i = 0; i < n; ++i)
    		sum += nums[i];
    	
    	bool f[sum/2+2];
    	memset(f,0,sizeof(f));
    	f[0] = true;
    	for (int i = 0; i < n; ++i)
    		for (int j = sum/2; j >= nums[i]; --j)
    			f[j] |= f[j-nums[i]];

    	int ans;
    	for (int j = sum/2; j >= 0; --j)
    		if (f[j])
    		{
    			ans = sum - 2*j;
    			break;
    		}
    	return ans;
    }
};
