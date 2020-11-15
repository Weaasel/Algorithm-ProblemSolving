//Travel
//Brute force
/*
  1번 점에서 출발하여 모든 점을 돌고 다시 1번 점으로 돌아왔을 때 주어진 거리만큼 여행할 수 있는 경로의 수를 구하는 문제이다.
  점이 8개 이하로 적기 때문에 1번을 제외한 나머지 점들의 여행순서를 정하는 7!가지의 경로를 전부 탐색하여 해결할 수 있다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define INF 1e15+7
#define eps 1e-8
#define DIV 998244353
#define pi 3.14159265

using namespace std;

int n, k, d[9][9], cnt;
int a[8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}
	for (int i = 0; i < n-1; i++) a[i] = i + 2;
	do {
		int tmp = 0, cur = 1;
		for (int i = 0; i < n - 1; i++) {
			tmp += d[cur][a[i]];
			cur = a[i];
		}
		tmp += d[cur][1];
		if (tmp == k) cnt++;
	} while (next_permutation(a, a + n));
	cout << cnt;

	return 0;
}
