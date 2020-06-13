//C - Ehab and Prefix MEXs

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
#define DIV 1000000007;
const ll INF = 1e9;

using namespace std;
int n;
int a[100001];
int b[100001];
int idx[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(b, -1, sizeof(b));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (idx[a[i]] == 0) idx[a[i]] = i;
	}
	bool flg = true;
	for (int i = 1; i <= n; i++) {
		if (idx[i] == 0) continue;
		if (idx[i] < i) flg = false;
	}

	queue<int> q; //남은idx 저장
	vector<int> v; //쓰는 idx
	for (int i = 0; i <= n; i++) if (idx[i] != 0) v.pb(i);
	if (v.size() == 1) {
		if(a[1] == 0) for (int i = 1; i <= n; i++) cout << 1 << " ";
		else for (int i = 1; i <= n; i++) cout << 0 << " ";
		return 0;
	}

	for (int i = 0; i < v.size();i++) {
		if (i == 0) {
			if (v[i] == 0) {
				q.push(1);
			}
			else {
				b[1] = 0;
			}
		}
		else {
			int curval = v[i], preval = v[i - 1], curidx = idx[v[i]], preidx = idx[v[i - 1]];
			int wlk = preval;
			for (int j = curidx; j > preidx; j--) {
				if (wlk == curval) {
					q.push(j);
				}
				else b[j] = wlk++;
			}
			while (!q.empty() && wlk < curval) {
				int aa = q.front(); q.pop();
				b[aa] = wlk++;
			}
		}
	}
	int valid = 1000000;

	for (int i = 1; i <= n; i++) {
		if (b[i] == -1) b[i] = valid--;
	}

	if (!flg) cout << -1;
	else {
		for (int i = 1; i <= n; i++) cout << b[i] << " ";
	}
	return 0;
}
