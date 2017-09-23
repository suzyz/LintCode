class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        if (source==NULL || target==NULL)
            return -1;
        int n = strlen(source), m = strlen(target);
        if (n<m)
            return -1;
        
        for (int i=0; i<n-m+1; i++) {
            bool flag = true;
            for (int j=0; j<m;j++)
                if(source[i+j]!=target[j]) {
                    flag = false;
                    break;
                }
            
            if (flag)
                return i;
        }
        return -1;
    }
};
