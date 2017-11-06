class Solution {
public:
    
    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
    	int n = nums1.size(), m = nums2.size();
    	sort(nums1.begin(), nums1.end());
    	sort(nums2.begin(), nums2.end());

    	vector<int> res;
    	int i = 0, j = 0;
    	while (i < n && j < m)
    	{
    		if (nums1[i] == nums2[j])
    		{
    			res.push_back(nums1[i]);
    			++i;
    			++j;

    			while (i < n && nums1[i] == nums1[i-1]) ++i;
    			while (j < m && nums2[j] == nums2[j-1]) ++j;    			
    		}
    		else
    		if (nums1[i] < nums2[j])
    			++i;
    		else
    			++j;
    	}
    	return res;
    }
};
