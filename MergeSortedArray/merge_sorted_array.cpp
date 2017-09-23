class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int *A, int m, int *B, int n) {
        int i=m-1,j=n-1;
        for (int k=m+n-1;k>=0;k--) {
            if (j<0 || A[i]>B[j]) {
                A[k] = A[i];
                i--;
            }
            else {
                A[k] = B[j];
                j--;
            }
        }
    }
};
