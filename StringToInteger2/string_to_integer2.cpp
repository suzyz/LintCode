class Solution {
public:
    /*
     * @param str: A string
     * @return: An integer
     */
    int atoi(string &str) {
    	string::iterator it = str.begin();
    	while (it != str.end() && *it == ' ') {
    		it = str.erase(it);
    	}

        int n = str.length();
        if (n==0) return 0;

        bool negative = false, decimal = false;
        if (str[0]=='-') {
        	negative = true;
        	str.erase(0,1);
        	n--;
        }
        else
        if (str[0]=='+') {
        	str.erase(0,1);
        	n--;
        }

        int i = 0, pos = 0;
        while (i<n) {
        	if (str[i] == '.') {
        		if (decimal)
        			return 0;
        		else {
        			pos = i;
        			decimal = true;
        		}
        	}
        	else
        	if (str[i]>'9' || str[i]<'0') {
        		n = i;
        		break;
        	}

        	i++;
        }

        if (decimal)
        	n = pos;

        if (negative && n>10)
        	return INT_MIN;
        if (!negative && n>10)
        	return INT_MAX;

        long long v = 0;
        i = 0;
        while (i<n) {
        	v = v*10 + str[i]-'0';
        	i++;
        }

        if (negative)
        	v *= -1;

        if (v>INT_MAX)
        	return INT_MAX;
        if (v<INT_MIN)
        	return INT_MIN;

        return v;
    }
};
