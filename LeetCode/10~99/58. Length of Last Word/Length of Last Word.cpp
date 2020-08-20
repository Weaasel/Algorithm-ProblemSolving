class Solution {
public:
    int lengthOfLastWord(string s) {
        int sz = s.size();
        int w = sz-1, cnt=0;
        while(w>=0&&s[w]==' ')w--;
        while(w>=0 && s[w]!=' ') cnt++,w--;
        return cnt;
    }
};
