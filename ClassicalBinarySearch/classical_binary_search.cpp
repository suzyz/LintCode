class Solution {
public:
    /*
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int findPosition(vector<int> &nums, int target) {
    	int l = 0, r = nums.size()-1;

    	while (l<=r)
    	{
    		int mid = l + ((r-l)>>1);
    		if (nums[mid] == target)
    			return mid;
    		else
    		if (nums[mid] < target)
    			l = mid+1;
    		else
    			r = mid-1;
    	}
    	return -1;
    }
};
