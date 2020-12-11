/*
  ()들의 조합으로 만들 수 있는 모든 경우를 만들고,
  각 경우가 valid한지 검사한다.
*/

class Solution {
public:
    char a[16];
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        for(int i=0;i<n;i++) a[i] = '(';
        for(int i=n;i<2*n;i++) a[i] = ')';
        do {
            stack<char> s;
            for(int i=0;i<2*n;i++) {
                if(s.empty() || a[i]=='(') s.push(a[i]);
                else {
                    if(s.top()=='(') s.pop();
                    else s.push(a[i]);
                }
            }
            if(!s.empty()) continue;
            string r = "";
            for(int i=0;i<2*n;i++) r += a[i];
            res.push_back(r);
        }while(next_permutation(a,a+2*n));
        return res;
    }
};
