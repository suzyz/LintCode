class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
    	vector<int> res = nums;
    	int n = nums.size();

    	for (int i = n-2; i>=0 ; --i)
    		if (nums[i] < nums[i+1])
    		{
    			int j = i+1;
    			while (j<n && nums[j]>nums[i])
    				++j;
    			--j;
    			res[i] = nums[j];
    			res[j] = nums[i];
    			nums[j] = nums[i];

    			for (int k = i+1; k < n; ++k)
    				res[k] = nums[n+i-k];
    			
    			return res;
    		}
    	
    	if (res.size() < 2)
    		return res;

    	for (int i = 0; i < n; ++i)
    		res[i] = nums[n-1-i];
    	return res;
    }
};
