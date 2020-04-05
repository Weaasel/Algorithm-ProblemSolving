//Vestigium

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
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int T, n, a[101][101], trace, rcnt, ccnt, flg;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		trace = 0, rcnt = 0, ccnt = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			set<int> s;
			flg = 0;
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (i == j) trace += a[i][j];
				if (s.count(a[i][j]) > 0) flg = 1;
				s.insert(a[i][j]);
			}
			if (flg == 1) rcnt++;
		}
		for (int j = 0; j < n; j++) {
			set<int> s;
			flg = 0;
			for (int i = 0; i < n; i++) {
				if (s.count(a[i][j]) > 0) flg = 1;
				s.insert(a[i][j]);
			}
			if (flg == 1) ccnt++;
		}
		cout << "Case #" << tc << ": " << trace << " " << rcnt << " " << ccnt << "\n";
	}
	return 0;
}
