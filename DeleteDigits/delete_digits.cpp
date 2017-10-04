class Solution {
public:
    /*
     * @param A: A positive integer which has N digits, A is a string
     * @param l: Remove k digits
     * @return: A string
     */

    string DeleteDigits(string &A, int l) {
    	string res;
        int n = A.length();

        int st = 0;
        for (int i = 0; i < n-l; ++i)
        {
            int k = st, en = l+i;

            for (int j = st+1; j <= en; ++j)
                if (A[j]<A[k])
                    k = j;
            
            res += A[k];
            st = k+1;
        }

        while (res.length()>1 && res[0] == '0')
            res.erase(res.begin());

    	return res;
    }
};