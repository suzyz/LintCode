class Solution {
public:
    /*
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> nums) {
        int n = nums.size();
        if (n==0)
            return 0;

        if (nums[0]<=nums[n-1])
            return nums[0];
        
        int l = 0, r = n-1;
        while (l<r) {
            int mid = l + ((r-l)>>1);
            if (nums[mid]>=nums[0]) {
                l = mid+1;
            }
            else
                r = mid;
        }
        return nums[l];
    }
};