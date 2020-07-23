//D - Unmerge
/*
  연습을 위해 풀이를 영어로 써봤다.
  To unmerge in 2 groups, at first we have to observe some elements must go together.
    Ex) 3 2 6 1 5 7 8 4, n = 4
    1. element after 8(4) must go with 8, since there is no element larger than 8, so that
    if 4 in another group, 4 will come out earlier than 8.
    -> (8, 4) must go together
    2. similarly, (7) go together, (6, 1, 5) must go together, (3, 2) must go together.
  
  Now we have 4 group: (3,2), (6,1,5), (7), (8,4) where their # of elements are [2, 3, 1, 2].
    Now, the question is, can we make 4 with sum of some combination made by [2, 3, 1, 2]?
    In this example, answer is 'YES'. (2+2 = 3+1 = 4.)
  We can compute this in O(n^2) with knapsack idea. (More precisely, O(min(2^n, n^2)). )
  With iterating i = 0 ~ n, check [possible combination sum in past] + a[i] is possible.
  This is in code line 60~71.  
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
int a[4001], idx[4001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i <= 2 * n; i++) {
            a[i] = 0, idx[i] = 0;
        }
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            idx[a[i]] = i;
        }
        int chk = 2 * n;
        vector<int> v;
        for (int i = 2 * n; i >= 1; i--) {
            if (chk <= idx[i]) continue;
            v.pb(chk - idx[i]);
            chk = idx[i];
        }
        bool vis[4001];
        for (int i = 0; i <= n; i++) vis[i] = false;
        int sz = v.size();
        vis[0] = true;
        for (int i = 0; i < sz; i++) {
            for (int j = n; j >= 0; j--) {
                if (j + v[i] <= n && vis[j]) {
                    vis[j + v[i]] = true;
                }
            }
        }
        if (vis[n]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
