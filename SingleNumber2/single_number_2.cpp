class Solution {
public:
    /*
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
    	int n = A.size(), count[33] = {0}, res = 0;

    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < 32; ++j)
    			if (A[i]&(1<<j))
    				++count[j];
    	}
    	for (int j = 0; j < 32; ++j)
    		if (count[j]%3)
    			res |= (1<<j);

    	return res;
    }
};
