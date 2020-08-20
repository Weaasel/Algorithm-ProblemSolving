#define ll long long
class Solution {
public:
    int myAtoi(string str) {
	    int flg = 1, wlk = 0, len = str.size();
	    ll res = 0;
	    while (wlk < len && str[wlk] == ' ') wlk++;
	    if (wlk < len && str[wlk] == '-') {
	    	flg = -1;
	    	wlk++;
	    }
        else if (wlk < len && str[wlk] == '+') {
	    	wlk++;
	    }

	    for (int i = wlk; i < len; i++) {
	    	if (str[i] > '9' || str[i] < '0') break;
	    	res *= 10;
	    	res += str[i] - '0';
            if(res > 2147483648LL) {
                if(flg==-1) return -2147483648;
                else return 2147483647;
            }
	    }
	    if (flg == -1) res *= flg;
    	return res;
    }
};
