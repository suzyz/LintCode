class Solution {
public:
    /*
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
    	int f[m+2];
    	memset(f,0,sizeof(f));
    	for (int i = 0; i < A.size(); ++i)
    		for (int j = m; j >= A[i]; --j)
    			f[j] = max(f[j], f[j-A[i]] + V[i]);

    	return f[m];
    }
};
