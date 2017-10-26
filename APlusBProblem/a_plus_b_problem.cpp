class Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
    	int x,y;

    	while (b)
    	{
    		x = a^b;
    		y = (a&b) << 1;

    		a = x;
    		b = y;
    	}
    	return a;
    }
};
