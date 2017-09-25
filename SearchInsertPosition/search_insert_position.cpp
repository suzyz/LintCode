class Solution {
public:
    /*
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &A, int target) {

    	if (A.size()==0)
    		return 0;
    	int l = 0, r = A.size()-1;
    	if (target>A[r])
    		return r+1;

    	while (l<r) {
    		int mid = l + ((r-l)>>1);

    		if (A[mid]==target)
    			return mid;

    		if (A[mid]<target)
    			l = mid+1;
    		else
    			r = mid;
    	}
    	return l;
    }
};
