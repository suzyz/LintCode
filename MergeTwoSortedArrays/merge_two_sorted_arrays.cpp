class Solution {
public:
    /*
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    	int n = A.size(), m = B.size(), i = 0, j = 0;
    	vector<int> ans;
    	while (i<n && j<m) {
    		if (A[i]<B[j]) {
    			ans.push_back(A[i]);
    			i++;
    		}
    		else {
    			ans.push_back(B[j]);
    			j++;
    		}
    	}

    	while (i<n)
    	{
    		ans.push_back(A[i]);
    		i++;
    	}
    	while (j<m)
    	{
    		ans.push_back(B[j]);
    		j++;
    	}
    	return ans;
    }
};
