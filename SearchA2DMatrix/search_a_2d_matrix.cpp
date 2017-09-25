class Solution {
public:
    /*
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
    	int n = matrix.size();
    	if (n==0) return false;

    	int m = matrix[0].size();
    	if (m==0) return false;

    	int l = 0, r = n-1;
    	while (l<r) {
    		int mid = l + ((r-l)>>1) + 1;
    		if (matrix[mid][0] == target)
    			return true;
    		if (matrix[mid][0] < target)
    			l = mid;
    		else
    			r = mid-1;
    	}
    	if (l>=n || matrix[l][0]>target)
    		return false;

    	int row = l;
    	l = 0;
    	r = m-1;
    	while (l<r) {
    		int mid = l + ((r-l)>>1);
    		if (matrix[row][mid] == target)
    			return true;
    		if (matrix[row][mid] < target)
    			l = mid+1;
    		else
    			r = mid-1;
    	}

    	if (l<m && matrix[row][l]==target)
    		return true;
    	else
    	if (r>=0 && matrix[row][r]==target)
    		return true;
    	else
    		return false;
    }
};
