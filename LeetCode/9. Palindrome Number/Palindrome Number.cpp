class Solution {
public:
    bool isPalindrome(int x) {
        string s;
        if(x<0) return false;
        else if(x==0) return true;
        while(x>0) {
            s += x%10 + '0';
            x /=10;
        }
        string revs = s;
        reverse(revs.begin(), revs.end());
        return s == revs;
    }
};
