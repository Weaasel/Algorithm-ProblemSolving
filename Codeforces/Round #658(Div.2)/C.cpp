//C1, C2 - Prefix Flip(Easy/Hard Version)
/*
  s1과 s2를 뒤에서부터 맞추면서 올건데,
  만약 현재 보는 문자와 맨앞 문자가 같다면 operation(i) 한 번으로 i번째 문자를 맞출 수 있다.
  맨앞과 현재 보는 문자가 다르다면 operation(1), operation(i) 로 맞출 수 있다.
  이렇게 하면 operation 로직은 해결됐다.
  
  문제는 이러면서 각 idx 가 어떤 문자인지를 유지해야 한다는 것인데, l, r만 유지하면 된다.
  초기상태: 1, 2, 3, 4, 5 l:1, r:5
  operation(5)를 한 후: 5 4 3 2 1 l:5, r:2
  이런식으로 operation이 한번 진행될때마다 l, r 을 뒤집고 상황에 맞게 r--, r++ 둘중 하나를 해주면 된다.
  '0' 인지 '1' 인지는 operation(i) 시행횟수에 달려있다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;
int T, n;
string s1, s2;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s1 >> s2;
        vector<int> res;
        int l = 0, r = n-1, cnt = 0;
        char front;
        for (int i = n - 1; i > 0; i--) {
            char tmp = s1[r];
            if (cnt % 2 == 1) tmp = tmp=='0'?'1':'0';

            if (tmp == s2[i]) {
                if (cnt % 2 == 0) r--;
                else r++;
                continue;
            }
            char back = s1[r];
            front = s1[l];
            if (cnt % 2 == 1) {
                back = back=='0'?'1':'0';
                front = front=='0'?'1':'0';
            }

            if (back == front) {
                res.pb(i + 1);
                swap(l, r);
                if (cnt % 2 == 1) r--;
                else r++;
                cnt++;
            }
            else {
                res.pb(1);
                if (s1[l] == '0') s1[l] = '1';
                else s1[l] = '0';
                res.pb(i + 1);
                swap(l, r);
                if (cnt % 2 == 1) r--;
                else r++;
                cnt++;
            }
        }
        if (cnt % 2 == 1) s1[l] = s1[l]=='0'?'1':'0';

        if (s1[l] != s2[0]) res.pb(1);
        cout << res.size() << " ";
        for (int r : res) cout << r << " ";
        cout << "\n";
    }
    return 0;
}
