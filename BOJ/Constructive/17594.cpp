//Stop Counting!
/*
  양쪽 끝 중 하나에서 시작하여 어느 부분에서 끝나는 부분수열이 최대의 평균값을 가진다는 사실이 보장된다.
  이를 증명하기까지 약간의 아이디어가 필요했다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <limits>
using namespace std;

int n;
double a[1000002];
double p1[1000002], p2[1000002];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	double res = 0;

	for (int i = 1; i <= n; i++) {
		p1[i] = a[i];
		p1[i] += p1[i - 1];
	}
	for (int i = n; i >= 1; i--) {
		p2[i] = a[i];
		p2[i] += p2[i + 1];
	}

	for (int i = 1; i <= n; i++) {
		res = max(res, p1[i] / i);
	}
	for (int i = n; i >= 1; i--) {
		res = max(res, p2[i] / (n -i + 1));
	}

	printf("%.7lf", res);

	return 0;
}
