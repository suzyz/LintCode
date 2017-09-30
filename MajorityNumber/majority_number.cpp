class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
    	if (nums.size() == 0)
    		return 0;
    	int ans = nums[0], count = 1, i = 1;
    	while (i<nums.size()) {
    		if (nums[i] == ans)
    			++ count;
    		else
    			-- count;

    		if (count == 0) {
    			++i;
    			if (i<nums.size()) {
    				ans = nums[i];
    				count = 1;
    			}
    		}
    		++i;
    	}

    	return ans;
    }
};