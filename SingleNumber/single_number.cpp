class Solution {
public:
    /*
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
    	int ans = 0;
    	for (int i = 0; i < A.size(); ++i)
    		ans ^= A[i];
    	return ans;
    }
};