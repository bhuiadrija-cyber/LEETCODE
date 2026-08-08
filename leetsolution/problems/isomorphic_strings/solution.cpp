class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for(int i=0;i<t.length();i++) {
            for (int k=i+1;k<t.length();k++){
                if (s[i]==s[k]){
                    if (t[i]!=t[k]) return false;
                }
                if (t[i]==t[k]){
                    if (s[i]!=s[k]) return false;
                }
            }
        }
        return true;
    }
};