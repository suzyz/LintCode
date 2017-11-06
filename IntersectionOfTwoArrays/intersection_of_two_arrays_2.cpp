class Solution {
public:
    
    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        int n = nums1.size();
        unordered_set<int> s(nums2.begin(), nums2.end()), res;
        for (int i = 0; i < n; ++i)
            if (s.count(nums1[i]))
                res.insert(nums1[i]);
        
        return vector<int> (res.begin(), res.end());
    }
};