class Solution {
public:
    /*
     * @param : the given array
     * @param : the window size
     * @return: the sum of the count of unique elements in each window
     */
    int slidingWindowUniqueElementsSum(vector<int> nums, int k) {
    	int n = nums.size();
    	if (n < k)
    		k = n;

    	if (k == 0)
    		return 0;

    	int ans = 0;
    	unordered_map<int,int> count;
    	for (int i = 0; i < k; ++i)
    		++count[nums[i]];	
    	for (unordered_map<int,int>::iterator it = count.begin(); it != count.end(); ++it)
    		if (it->second == 1)
    			++ans;
    	
    	for (int i = k; i < n; ++i)
    	{
    		--count[nums[i-k]];
    		++count[nums[i]];

    		if (count[nums[i-k]] == 0)
    			count.erase(nums[i-k]);
    		
    		for (unordered_map<int,int>::iterator it = count.begin(); it != count.end(); ++it)
	    		if (it->second == 1)
    				++ans;
    	}
    	return ans;
    }
};
