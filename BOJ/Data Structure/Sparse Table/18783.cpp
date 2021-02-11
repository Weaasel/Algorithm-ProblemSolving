//Swapity Swapity Swap
//Sparse Table
/*
  m번의 연산을 k번 했을 때 결과값을 출력하는 문제이다.
  m번의 연산을 한 번 하는것은 시간제한에 걸리지 않고, k가 크기 때문에 k번의 연산을 빠르게 하는 것이 중요하다.
  이럴 때 유용한 자료구조가 sparse table이고, 이 문제의 경우는 풀이도 명료하다.
  2^i번 연산결과를 table에 저장해두고 k를 2진 분해하며 최대 logk번의 연산을 수행하면 된다.
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, k;
int a[101010][40], res[101010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) a[i][0] = i;
	for (int j = 0; j < m; j++) {
		int l, r; cin >> l >> r;
		for (int i = l; i <= (l + r) / 2; i++) 
			swap(a[i][0], a[r - i + l][0]);		
	}
	for (int i = 1; i < 40; i++) {
		for (int j = 1; j <= n; j++) {
			a[j][i] = a[a[j][i - 1]][i - 1];
		}
	}
	for (int i = 1; i <= n; i++) res[i] = i;
	for (int i = 39; i >= 0; i--) {
		if (k >= (1LL << i)) {
			for (int j = 1; j <= n; j++) {
				res[j] = a[res[j]][i];
			}
			k -= (1LL << i);
		}
	}

	for (int i = 1; i <= n; i++) cout << res[i] << "\n";
	return 0;
}
