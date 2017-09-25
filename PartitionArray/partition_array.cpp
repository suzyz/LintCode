class Solution {
public:
    /*
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        int n = nums.size();
        if (n==0)
            return 0;
        
        int idx=0;
        for (int i=0;i<n;i++) {
            if (nums[i]<k) {
                if (idx!=i) {
                    int tmp = nums[idx]; nums[idx]=nums[i]; nums[i]=tmp;
                }
                idx++;
            }
        }
        return idx;
    }
};
