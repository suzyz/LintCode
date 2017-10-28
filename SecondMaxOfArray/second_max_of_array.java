public class Solution {
    /*
     * @param : An integer array
     * @return: The second max number in the array.
     */
    public int secondMax(int[] nums) {
    	int n = nums.length;
    	int max1 = Math.max(nums[0],nums[1]);
    	int max2 = Math.min(nums[0],nums[1]);
    	for (int i = 2; i<n ; ++i) {
    		if (nums[i] > max1)
    		{
    			max2 = max1;
    			max1 = nums[i];
    		}
    		else
    		if (nums[i] > max2)
    			max2 = nums[i];
    	}
    	return max2;
    }
}
