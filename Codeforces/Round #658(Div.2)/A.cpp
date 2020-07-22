//A - Common Subsequence
/*
  두 배열에서 동시에 등장하는 값이 있으면 그 값이 답이 되는 문제.
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
int T, n, m, num;
bool a[1001], b[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i <= 1000; i++) {
            a[i] = false;
            b[i] = false;
        }
        for (int i = 0; i < n; i++) {
            cin >> num;
            a[num] = true;
        }
        for (int i = 0; i < m; i++) {
            cin >> num;
            b[num] = true;
        }
        bool f = false;
        for (int i = 1; i <= 1000; i++) {
            if (a[i] && b[i]) {
                cout << "YES\n";
                cout << 1 << " " << i << "\n";
                f = true;
                break;
            }
        }
        if (!f) cout << "NO\n";
    }
    return 0;
}
