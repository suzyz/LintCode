class Solution {
public:
    /*
     * @param : the given number
     * @return: whether whether there're two integers
     */
    bool checkSumOfSquareNumbers(int num) {
    	int l = 0, r = sqrt(num);
   		while (l <= r)
   		{
   			int tmp = num - l*l;
   			if (tmp == r*r)
   				return true;
   			else
   			if (tmp < r*r)
   				--r;
   			else
   				++l;
   		}
   		return false;
    }
};
