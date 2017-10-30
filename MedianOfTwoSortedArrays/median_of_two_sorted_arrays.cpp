class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
    	int tot = A.size() + B.size();
    	if (tot == 0)
    		return 0;

    	if (tot%2)
    		return binary_search(tot/2,A,B);
    	else
    		return 0.5 * (binary_search(tot/2-1,A,B) + binary_search(tot/2,A,B));
    }

    int binary_search(int target,vector<int> &A,vector<int> &B)
    {
    	int n = A.size(), m = B.size();
    	int l1 = 0, r1 = n-1, l2 = 0, r2 = m-1;

    	while (l1 < r1 && l2 < r2)
    	{
    		
    	}
    }
};
