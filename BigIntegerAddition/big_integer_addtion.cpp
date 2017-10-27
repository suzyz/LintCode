class Solution {
public:
    /*
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        int n = num1.length()-1, m = num2.length()-1;
        string res;
        int carry = 0;
        while (n>=0 && m>=0)
        {
            int d = num1[n] + num2[m] - '0' - '0' + carry;
            carry = d/10;
            res += ('0' + d%10);
            --n;
            --m;
        }
        while (n>=0)
        {
            int d = num1[n] - '0' + carry;
            carry = d/10;
            res += ('0' + d%10);
            --n;
        }

        while (m>=0)
        {
            int d = num2[m] - '0' + carry;
            carry = d/10;
            res += ('0' + d%10);
            --m;
        }

        if (carry)
            res += ('0' + carry);

        reverse(res.begin(), res.end());
        return res;
    }
};