//D. Carousel

#include <iostream>
#include <cstdio>
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
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int T, n, used;
int main() {
	cin >> T;
	while (T--) {
		used = 1;
		cin >> n;
		vector<int> fig(n), col(n);
		for (int i = 0; i < n; i++) cin >> fig[i];
		col[0] = 1;
		for (int i = 1; i < n - 1; i++) {
			if (fig[i] == fig[i - 1]) col[i] = col[i - 1];
			else {
				used = 2;
				col[i] = 3 - col[i - 1];
			}
		}
		if (fig[n - 1] == fig[n - 2]) {
			if (fig[n - 1] == fig[0]) col[n - 1] = col[0];
			else {
				used = 2;
				col[n - 1] = 3 - col[0];
			}
		}
		else if (fig[n - 1] == fig[0]) {
			if (fig[n - 1] == fig[n - 2]) col[n - 1] = col[n - 2];
			else {
				used = 2;
				col[n - 1] = 3 - col[n - 2];
			}
		}
		else {
			if (col[n - 2] == col[0]) {
				used = 2;
				col[n - 1] = 3 - col[0];
			}
			else {
				used = 3;
				col[n - 1] = 3;
			}
		}

		int flg = 0, idx=0;
		if (used == 3) {
			for (int i = 0; i <= n - 3; i++) {
				if (fig[i] == fig[i + 1]) {
					flg = 1;
					idx = i + 1;
					break;
				}
			}
			if (flg == 1) {
				for (int i = idx; i <= n - 2; i++) {
					col[i] = 3 - col[i];
				}
				if (col[0] == col[n - 2]) {
					used = 2;
					col[n - 1] = 3 - col[0];
				}
			}
		}

		cout << used << "\n";
		for (int i = 0; i < n; i++) cout << col[i] << " ";
		cout << "\n";
	}
	return 0;
}
