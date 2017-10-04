class Solution {
public:
    /*
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
    	int max_idx = 0, n = A.size();
    	for (int i = 0; i < n; ++i)
    	{
    		if (i>max_idx)
    			break;
    		max_idx = max_idx > i+A[i] ? max_idx:i+A[i];
    		if (max_idx >= n-1)
    			return true;
    	}
    	return max_idx >= n-1;
    }
};
