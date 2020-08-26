//스터디 그룹
//two pointer, sorting

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
#define MAX 
#define DIV 1000000
#define INF 2000000000

using namespace std;

int n, k, D, md, num, idx[100001], d[100001], cnt[31], l = 1, r = 1;
int res;

vector<int> algo[100001];

bool cmp(int a, int b) {
	return d[a] < d[b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> D;
	for (int i = 1; i <= n; i++) idx[i] = i;

	for (int i = 1; i <= n; i++) {
		cin >> md >> d[i];
		for (int j = 0; j < md; j++) {
			cin >> num;
			algo[i].pb(num);
		}
	}

	sort(idx + 1, idx + n + 1, cmp);
	for (int v : algo[idx[r]]) {
		cnt[v]++;
	}
	while (r <= n) {
		if (d[idx[r]] - d[idx[l]] <= D) {
			//처리
			int a = 0, b = 0;
			for (int i = 1; i <= k; i++) {
				if (cnt[i]) a++;
				if (cnt[i] == r - l + 1) b++;
			}

			res = max(res, (a - b)*(r - l + 1));

			r++;
			//새로들어온애에 대한 처리
			for (int v : algo[idx[r]]) {
				cnt[v]++;
			}
		}
		else {
			//빠질애에대한 처리
			for (int v : algo[idx[l]]) {
				cnt[v]--;
			}
			l++;
		}
	}
	cout << res;
	return 0;
}
