//B - Sequential Nim
/*
  내 앞에 놓인 더미의 돌 개수가 1만 아니면 주도권이 나에게 있다.
  즉, 나는 상대방의 행동을 강제할 수 있다.
  1. 다음 더미가 1이 아니라면 이번 더미에서 1개만 남기고 가져가 다음 더미의 주도권도 가져온다.
  2. 다음 더미가 1이라면 이번 더미에서 전부 가져가고 상대에게 다음 더미(1개) 를 가져가게 만들면서 주도권을 가져온다.
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
int a[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        bool t = true;
        int i;
        for (i = 0; i < n; i++) {
            if (a[i] != 1) break;
            t = !t;
        }
        if (t) {
            if (i == n) cout << "Second\n";
            else cout << "First\n";
        }
        else {
            if (i == n)cout << "First\n";
            else cout << "Second\n";
        }
    }
    return 0;
}
