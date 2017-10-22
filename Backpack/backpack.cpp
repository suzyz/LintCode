class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        int n = A.size();
        bool f[m+2];
        memset(f,0,sizeof(f));
        f[0] = true;
        for (int i = 0; i < n; ++i)
        	for (int j = A[i]; j <= m; ++j)
	        	f[j] |= f[j-A[i]];
        
        for (int i = m; i >= 0; --i)
        	if (f[i])
	        	return i;
	    return 0;
    }
};
