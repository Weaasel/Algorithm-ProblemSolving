//PPC 2019. Good Pizza, Great Pizza
//마름모의 넓이. long long overflow에 주의. 4e9 * 4e9 연산을 해야 할 일이 

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using lint = long long;
using ii = pair<int, int>;

const int mxn = 200020;
lint N, a[mxn], b[mxn], d[mxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		lint x, y;
		cin >> x >> y;
		a[i] = x + y, b[i] = x - y;
	}
	sort(a, a + N); sort(b, b + N);
	lint x = b[N - 1] - b[0];
	lint y = a[N - 1] - a[0];
	x = max(x, y);
	if (x % 2) cout << (x / 2) * x + x/2 << ".5";
	else cout << (x / 2) * x;
	return 0;
}
