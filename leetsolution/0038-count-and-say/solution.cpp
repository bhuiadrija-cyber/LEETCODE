class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        string ztr="";
        int freq=1;
        char ch=s[0];
        for(int i=1;i<s.length();i++){
            char c=s[i];
            if(ch==c) freq++;
            else{
                ztr+=(to_string(freq)+ch);
                freq=1;
                ch=c;
            }
        }
        ztr+=(to_string(freq)+ch);
        return ztr;
    }
};
