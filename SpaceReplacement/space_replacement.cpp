class Solution {
public:
    /*
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
    	int res = length;
    	for (int i = 0; i < length; ++i)
    		if (string[i] == ' ')
    			res += 2;

    	int idx = res-1;
    	for (int i = length-1; i >= 0; --i)
    		if (string[i] == ' ')
    		{
    			string[idx--] = '0';
    			string[idx--] = '2';
    			string[idx--] = '%';
    		}
    		else
    			string[idx--] = string[i];
    		
    	return res;
    }
};
