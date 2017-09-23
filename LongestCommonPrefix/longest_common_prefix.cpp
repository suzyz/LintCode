class Solution {
public:
    /*
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        string ans;
        
        if (n==0)
            return "";
            
        if (n==1)
            return strs[0];
        
        for (int i=0;i<strs[0].length();i++) {
            for(int j=1;j<n;j++)
                if(strs[j][i]!=strs[0][i])
                    return ans;
                    
            ans += strs[0][i];
        }
        return ans;
    }
};
