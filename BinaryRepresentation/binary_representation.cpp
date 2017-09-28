#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    /*
     * @param n: Given a decimal number that is passed in as a string
     * @return: A string
     */
    string binaryRepresentation(string &n) {
    	int len = n.length();
    	int pos = n.find('.');
    	if (pos == string::npos)
    		pos = len;

    	string integral,fractional;

    	long long weight = 5, sum = 0;
    	int i = 1;
    	while (i<33 && pos+i<len) {
    		sum = 10*sum + n[pos+i] - '0';
    		if (sum >= weight) {
    			while (sum >= weight) {
    				sum -= weight;
    				fractional+='1';
    				weight *= 5;
    			}
    		}
    		else {
    			weight *= 5;
    			fractional+='0';
    		}

    		++i;
    	}

    	if (sum > 0)
 			return "ERROR";

    	while (pos+i<len) {
    		sum = 10*sum + n[pos+i] - '0';
    		if (sum > 0)
 				return "ERROR";
    		++i;
    	}

    	sum = 0;
    	i = 0;
    	while (i<pos) {
    		sum = 10*sum + n[i] - '0';
    		++i;
    	}

    	weight = 1;
    	for (int j = 0; sum>0 ; ++j)
    	{
    		if (weight & sum) {
    			sum -= weight;
    			integral = '1' + integral;
    		}
    		else
    			integral = '0' + integral;

    		weight <<= 1;
    	}

    	bool zero = true;
    	for (int j = 0; j<fractional.length(); j++)
    		if (fractional[j] != '0') {
    			zero = false;
    			break;
    		}

    	if(!zero)
    		while (fractional.length()>0 && fractional[fractional.length()-1]=='0')
    			fractional.erase(fractional.length()-1);

    	if (integral.length()==0)
    			integral = "0";
    		
    	if (zero)
    		return integral;
    	else
    		return integral + '.' + fractional;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string n("1.0");
	cout<<s.binaryRepresentation(n)<<endl;
	return 0;
}