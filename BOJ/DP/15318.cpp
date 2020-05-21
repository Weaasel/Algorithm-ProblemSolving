//새로운 수열
//Prefix sum
/*
  주어진 형태를 만들기 위해 2개의 수열을 사용했어야 했다.
  2020 google kickstart C의 마지막 문제와 완전히 같은 아이디어다.
  차이점이 있다면 이 문제에서는 구간의 크기가 정해져있고, 업데이트가 없어 prefix sum만으로 해결이 가능하다는 점이다.
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
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 2e18
#define base 100000
using namespace std;
int n;
ll a[600001], ps1[600001], ps2[600001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n; i++) {
		ll k = i % 2 == 1 ? 1 : -1;
		ps1[i] = k * i * a[i];
		ps1[i] += ps1[i - 1];
		ps2[i] = k * a[i];
		ps2[i] += ps2[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		ll res = ps1[i + n - 1] - ps1[i-1];
		res -= (ps2[i + n - 1] - ps2[i - 1])*(i-1);
		if (i % 2 == 0) res *= -1;
		cout << res << " ";
	}

	return 0;
}
