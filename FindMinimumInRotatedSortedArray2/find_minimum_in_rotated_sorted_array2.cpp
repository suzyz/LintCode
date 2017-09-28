class Solution {
public:
    /*
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> nums) {
    	int l = 0, r = nums.size()-1;
    	if (r<0)
    		return 0;

    	int first = nums[0];

    	while (l<r && nums[l]==first)
    		l++;

    	while (l<r && nums[r]==first)
    		r--;

    	while (l<r) {
    		int mid = l + ((r-l)>>1);

    		if (nums[mid]>first) {
    			l = mid + 1;
    		}
    		else
    			r = mid;
    	}
    	return first<nums[l] ? first:nums[l];
    }
};
