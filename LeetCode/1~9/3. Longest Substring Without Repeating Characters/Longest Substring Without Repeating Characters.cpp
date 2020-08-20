class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len==0) return 0;
        int cnt[256], l = 0, r = 0, res = 0, tmp;
        for(int i=0;i<256;i++) cnt[i] = 0;
        cnt[s[l]]++;
        while(r<len) {
            bool flg = false;
            for(int i=0;i<256;i++) if(cnt[i] > 1) flg = true;
            if(flg) {
                cnt[s[l]]--;
                l++;
            }
            else {
                int tmp=0;
                for(int i=0;i<256;i++) if(cnt[i]==1) tmp++;
                res = max(res, tmp);
                r++;
                if(r==len) break;
                cnt[s[r]]++;
            }
        }
        return res;
    }
};
