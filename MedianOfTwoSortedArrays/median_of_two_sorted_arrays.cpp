#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
    	int tot = A.size() + B.size();
    	if (tot == 0)
    		return 0;

        int m = A.size(), n = B.size();
    	if (tot%2)
    		return find_kth(0,m,A,0,n,B,tot/2+1);
    	else
    		return 0.5 * (find_kth(0,m,A,0,n,B,tot/2) + find_kth(0,m,A,0,n,B,tot/2+1));
    }

    int find_kth(int base1,int len1, vector<int> &A, int base2, int len2, vector<int> &B, int k)
    {
        if (len1 > len2)
            return find_kth(base2,len2,B,base1,len1,A,k);
        if (len1 == 0)
            return B[base2 + k-1];
        if (k == 1)
            return min(A[base1],B[base2]);

        int half1 = min(k/2, len1);
        int half2 = k - half1;
        if (A[base1 + half1 - 1] == B[base2 + half2 - 1])
            return A[base1 + half1 - 1];
        else
        if (A[base1 + half1 - 1] < B[base2 + half2 - 1])
            return find_kth(base1 + half1, len1 - half1, A, base2,len2,B, k - half1);
        else
            return find_kth(base1,len1,A, base2 + half2, len2 - half2, B, k - half2);
    }
};

int main()
{
    Solution s;
    int d1[] = {1,2,3,4,5,6}, d2[] = {2,3,4,5,7,8};
    vector<int> A(d1,d1+6), B(d2,d2+6);
    cout << "median:" << s.findMedianSortedArrays(A,B) << endl;
}
