class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        int l = 0, r = array.size() - 1;
        if (r<0)
        	return -1;

        while (l<r) {
        	int mid = l + ((r-l)>>1);

        	if (array[mid]==target)
        		r = mid;
        	else
        	if (array[mid]<target)
        		l = mid+1;
        	else
        		r = mid-1;
        }
        if (array[l]==target)
        	return l;
        else
        	return -1;
    }
};