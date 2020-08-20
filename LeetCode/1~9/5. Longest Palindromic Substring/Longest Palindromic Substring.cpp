class Solution {
public:
    string longestPalindrome(string s) {
        bool palin[1001][1001];
        int len = s.size();
        for(int i=0;i<len;i++) {
            for(int j=0;j<len;j++) {
                palin[i][j] = false;
            }
        }
        for(int i=0;i<len;i++) palin[i][i] = true;
        for(int i=0;i<len-1;i++) {
            if(s[i] == s[i+1]) palin[i][i+1] = true;
        }
        for(int l=2;l<len;l++) {
            for(int st=0; st < len-l;st++) {
                int e = st+l;
                if(palin[st+1][e-1] && s[st] == s[e]) palin[st][e] = true;
            }
        }
        for(int l=len-1;l>=0;l--) {
            for(int st=0;st<len-l;st++) {
                int e = st+l;
                if(palin[st][e]) {
                    return s.substr(st, l + 1);
                }
            }
        }
        return "";
    }
};
