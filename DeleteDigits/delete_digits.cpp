class Solution {
public:
    /*
     * @param A: A positive integer which has N digits, A is a string
     * @param l: Remove k digits
     * @return: A string
     */

    string DeleteDigits(string &A, int l) {
    	int count[10];
    	memset(count,0,sizeof(count));

    	for (int i = 0; i < A.length(); ++i)
    		count[A[i]-'0']++;

    	for (int i = 9; i >=0 && l > 0; --i)
    	{
    		if (l >= count[i])
    		{
    			l-=count[i];
    			for (int j = 0; j < A.length(); ++j)
    			{
    				if (A[j] == '0'+i)
    					A.erase(j,1);
    			}
    		}
    		else
    		{
    			l = 0;
    			int sum = 0;
    			for (int j = 0; j < A.length() && sum < l ; ++j)
    			{
    				if (A[j] == '0'+i)
    				{
    					A.erase(j,1);
    					++sum;
    				}
    			}
    		}
    	}
    	return A;
    }
};