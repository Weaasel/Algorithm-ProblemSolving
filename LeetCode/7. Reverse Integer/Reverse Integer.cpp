#define ll long long
class Solution {
public:
    int reverse(int x) {
        ll xx = x;
        ll flg = 1;
        if(xx < 0) {
            xx *= -1;
            flg = -1;
        }
        string s;
        while(xx>0) {
            s += xx%10 + '0';
            xx /=10;
        }
        ll res = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++) {
            res*=10;
            res+=s[i]-'0';
        }
        if(flg==-1) res*=-1;
        ans = res;
        if(res==ans) return ans;
        else return 0;
    }
};
