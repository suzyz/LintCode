class Solution {
public:
    /*
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean 
     */
    bool search(vector<int> &A, int target) {
    	int l = 0, r = A.size()-1;
    	if (r<0)
    		return false;

    	if (A[0] == target)
    		return true;

    	while (l<r && A[l] == A[0])
    		l++;
    	while (l<r && A[r] == A[0])
    		r--;

    	while (l<r) {
    		int mid = l + ((r-l)>>1);
    		if (A[mid] == target)
    			return true;

    		if (target > A[0] && A[mid] > A[0]) {
    			if (A[mid] > target)
    				r = mid-1;
    			else
    				l = mid+1;
    		}
    		else
    		if (target > A[0] && A[mid] < A[0]) {
    			r = mid-1;
    		}
    		else
    		if (A[mid] > A[0]) {
    			l = mid+1;
    		}
    		else {
    			if (A[mid] < target)
    				l = mid+1;
    			else
    				r = mid-1;
    		}
    	}

    	return A[l]==target;
    }
};