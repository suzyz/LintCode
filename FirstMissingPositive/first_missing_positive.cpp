class Solution {
public:
    /*
     * @param A: An array of integers
     * @return: An integer
     */
    int firstMissingPositive(vector<int> &A) {
        int n = A.size();
        
        for (int i=0;i<n;i++)
            if (A[i]<=0)
                A[i] = n+1;
        
        for (int i=0;i<n;i++) {
            int cur = abs(A[i]);
            if (cur<=n && A[cur-1]>0)
                A[cur-1] *= -1;
        }
        
        for (int i=0;i<n;i++) {
            if (A[i]>0)
                return i+1;
        }
        return n+1;
    }
};
