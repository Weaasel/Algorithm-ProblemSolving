class Solution {
public:
    int romanToInt(string s) {
        int res = 0, tmp = 0, len = s.size();
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int wlk = 0;
        while(wlk<len) {
            if(wlk==len-1) {
                res += m[s[wlk]];
                wlk++;
            }
            else if(m[s[wlk]] < m[s[wlk+1]]) {
                res += m[s[wlk+1]] - m[s[wlk]];
                wlk+=2;
            }
            else {
                res += m[s[wlk]];
                wlk++;
            }
        }
        return res;
    }
};
