class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if(numRows==1) return s;
        string ss[10001];
        for(int i=0;i<numRows;i++) {
            ss[len] = "";
        }
        int wlk = 0, flg = 1;
        for(int i=0;i<len;i++) {
            ss[wlk].push_back(s[i]);
            wlk += flg;
            if(wlk == numRows) {
                wlk -= 2;
                flg = -1;
            }
            else if(wlk == -1) {
                wlk += 2;
                flg = 1;
            }
        }
        string res = "";
        for(int i=0;i<len;i++) {
            res += ss[i];
        }
        return res;
    }
};
