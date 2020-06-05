class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size(), wlk = 0;
        string res = "";
        if(sz==0) return res;
        vector<int> szs;
        for(int i=0;i<sz;i++) {
            szs.push_back(strs[i].size());
        }
        while(1) {
            bool flg = true;
            char c = '0';
            for(int i=0;i<sz;i++) {
                if(wlk >= szs[i]) {
                    return res;
                }
                if(c == '0') c = strs[i][wlk];
                if(strs[i][wlk] != c) flg = false;
            }
            if(flg) res += c;
            else break;
            wlk++;
        }
        return res;
    }
};
