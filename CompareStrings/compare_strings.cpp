class Solution {
public:
    /*
     * @param A: A string
     * @param B: A string
     * @return: if string A contains all of the characters in B return true else return false
     */
    bool compareStrings(string &A, string &B) {
        int n = A.length(), m = B.length();
        if (n<m)
            return false;
            
        int count[26];
        memset(count,0,sizeof(count));
        for (int i=0; i<n; i++)
            count[A[i]-'A']++;
        
        for (int i=0; i<m; i++)
            count[B[i]-'A']--;
            
        for (int i=0; i<26; i++)
            if(count[i]<0)
                return false;
        return true;
    }
};
