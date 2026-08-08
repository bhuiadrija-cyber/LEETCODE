class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string s="";
        sort(strs.begin(),strs.end());
        int m=min(strs[0].length(),strs[n-1].length());
        for (int i=0;i<m;i++){
            if (strs[0][i]==strs[n-1][i]) s+=strs[0][i];
            else break;
        }
        return s;
    }
};