class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: the maximun difference
     */
    int maximumGap(vector<int> &nums) {
        int n = nums.size();
        if (n<2)
        	return 0;
        int minv = nums[0], maxv = nums[0];
        for (int i = 1; i < n; ++i)
        {
        	minv = min(minv,nums[i]);
        	maxv = max(maxv,nums[i]);
        }

        if (minv == maxv)
            return 0;
        
        int len = ceil(1.0 * (maxv - minv) / (n-1));
        int m = ceil(1.0 * (maxv - minv) / len) + 1;
        set<int> buckets[m];
        for (int i = 0; i < n; ++i)
        {
        	int cur = (nums[i] - minv)/len;
        	buckets[cur].insert(nums[i]);
        }

        bool is_first = true;
        int last = 0, ans = 0;
        for (int i = 0; i < m; ++i)
        {
        	if (buckets[i].size() == 0)
        		continue;
        	if (is_first)
        		is_first = false;	
        	else
        		ans = max(ans, *buckets[i].begin() - *buckets[last].rbegin());
        	
        	last = i;
        }
        return ans;
    }
};
