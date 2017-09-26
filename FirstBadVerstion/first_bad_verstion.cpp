/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/

class Solution {
public:
    /*
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int l = 1, r = n;
        while (l<r) {
            int mid = l + ((r-l)>>1);
            if (SVNRepo::isBadVersion(mid))
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};