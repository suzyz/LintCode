class Solution {
public:
    /*
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        int n = A.size();
        if (n==0)
            return -1;
            
        int l = 0, r = n-1;
        while (l<r) {
            int mid = l + ((r-l)>>1);

            if (A[mid]==target) return mid;

            if (target >= A[0]) {
                if (A[mid] >= A[0]) {
                    if (A[mid] > target)
                        r = mid-1;
                    else
                        l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }
            else {
                if (A[mid] >= A[0])
                    l = mid+1;
                else {
                    if (A[mid] > target)
                        r = mid-1;
                    else
                        l = mid+1;
                }
            }
        }
        if (A[l]==target)
            return l;
        else
            return -1;
    }
};