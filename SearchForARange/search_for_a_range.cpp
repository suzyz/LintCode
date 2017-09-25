class Solution {
public:
    /*
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
    	vector<int> ans;
        int n = A.size();
        int l = 0, r = n-1;
        while (l<r) {
        	int mid = l + ((r-l)>>1);
        	if (A[mid]==target)
        		r = mid;
        	else
        	if (A[mid]<target)
        		l = mid+1;
        	else
        		r = mid-1;
        }

        if (l>=n || A[l]!=target) {
        	ans.push_back(-1);
        	ans.push_back(-1);
        	return ans;
        }
        else
        	ans.push_back(l);

        r = n-1;
        while (l<r) {
        	int mid = l + ((r-l)>>1) + 1;
        	if (A[mid]==target)
        		l = mid;
        	else
        	if (A[mid]<target)
        		l = mid+1;
        	else
        		r = mid-1;
        }
        ans.push_back(r);
        return ans;
    }
};
