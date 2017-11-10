#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return product of num1 and num2
     */
    string multiply(string &num1, string &num2) {
    	int n = num1.length(), m = num2.length();
    	if (n == 0 || m == 0)
    		return "";

    	if ((n==1 && num1[0] == '0') || (m==1 && num2[0] == '0'))
    		return "0";

    	bool done[10];
    	string product[10];
    	memset(done,0,sizeof(done));
    	done[0] = true;
    	product[0] = "0";

    	for (int i = n-1; i >= 0; --i)
    		num1[i] -= '0';
    	for (int i = m-1; i >= 0; --i)
    		num2[i] -= '0';

    	reverse(num1.begin(), num1.end());
    	reverse(num2.begin(), num2.end());

    	string ans = "0" - '0';
    	for (int i = 0; i < n; ++i)
    	{
    		if (!done[num1[i]])
    		{
    			done[num1[i]] = true;
    			multiply_big_and_small(num2,num1[i],product[num1[i]]);
    		}

    		string tmp = product[num1[i]];
    		for (int j = 0; j < i; ++j)
    			tmp = (char)0 + tmp;

    		add(ans,tmp);
    	}

    	for (int i = 0; i < ans.length(); ++i)
    		ans[i] += '0';
    	
    	reverse(ans.begin(), ans.end());
    	return ans;
    }

    void add(string &a, string &b) /* a+=b */
    {
    	int l1 = a.length() , l2 = b.length(), i = 0, carry = 0;

    	while (i < l1 && i < l2)
    	{
    		a[i] += carry + b[i];
    		carry = a[i]/10;
    		a[i] %= 10;

    		++i;
    	}

    	while (i < l2)
    	{
    		int cur = carry + b[i];
    		carry = cur/10;
    		a += (char)(cur%10);

    		++i;
    	}
   	
	    while (carry)
	    {
	    	if (i == a.length())
	    		a += (char)0;

	    	a[i] += carry;
	    	carry = a[i]/10;
	    	a[i] %= 10;

	    	++i;
	    }		
    }

    void multiply_big_and_small(string &a,int b,string &c) /* c = a*b, where b != 0 */
    {
    	c = a;
    	int carry = 0;
    	for (int i = 0; i < c.length(); ++i)
    	{
    		c[i] = carry + c[i] * b;
    		carry = c[i]/10;
    		c[i] %= 10;
    	}

    	if (carry)
    		c += (char)carry;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string a = "123", b = "45";
	cout << s.multiply(a,b) << endl;
	return 0;
}
