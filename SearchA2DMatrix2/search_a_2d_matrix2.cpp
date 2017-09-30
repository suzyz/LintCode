class Solution {
public:
    /*
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m==0)
            return 0;
        int n = matrix[0].size();

        int i = 0, j = n-1, ans = 0;
        while (i<m && j>=0) {
            if (matrix[i][0] > target)
                break;

            while (j>=0 && matrix[i][j] > target)
                --j;

            if (j<0)
                break;

            if (matrix[i][j]==target)
                ++ans;

            ++i;
        }
        return ans;
    }
};