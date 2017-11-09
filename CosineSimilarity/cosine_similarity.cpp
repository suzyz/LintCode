class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: Cosine similarity
     */
    double cosineSimilarity(vector<int> &A, vector<int> &B) {
    	int n = A.size();
    	double product = 0, magnitude_a = 0, magnitude_b = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		product += A[i] * B[i];
    		magnitude_a += A[i] * A[i];
    		magnitude_b += B[i] * B[i];
    	}

    	if (fabs(magnitude_a) < 1e-8 || fabs(magnitude_b) < 1e-8)
    		return 2.0000;

    	return product/sqrt(magnitude_a)/sqrt(magnitude_b);
    }
};
