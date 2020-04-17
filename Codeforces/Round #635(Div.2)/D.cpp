// D - Xenia and Colorful Gems	

/*
목적은 l, m, r 세 수를 각 집합에서 뽑았을 때,
(l-m)^2 + (m-r)^2 + (l-r)^2 을 minimize하고 싶다. 즉 l, m, r이 옹기종기 모여있는 것이 가장 optimal일 것으로 보인다. 

3개의 집합에 대해서 loop를 돌릴거고, 어떤 한 수를 mid로 잡았을 때, 나머지 두 집합에서
left <= mid <= right가 되는 mid와 가장 가까운 left, right를 얻을 수 있도록 뽑을 것이다.

left는 한 집합에서 mid에 대해 lower_bound를 때리고,
그랬을 때 나올 수 있는 3가지 경우의 수(mid와 같은, vector.end(), mid보다 큰) 에 대해서
적절히 처리해준다. (뒤의 두 경우에 대해서만 left--)

right는 나머지 한 집합에서 mid에 대해 upper_bound를 때리고,
나올 수 있는 2가지 경우의 수(mid 초과, vector.end()) 에 대해서
적절히 처리해준다. (vector.end()이거나 vector[r-1] == mid면 r--)

이렇게 하고 l, r이 모두 0 이상이어야 valid한 경우이므로 이때만 처리해 준다.
*/

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
#define all(v) (v).begin(),(v).end()
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;
int T;

vector<ll> a[3];
int aa, bb, cc;
ll n;

//lb-1. ub-1.
ll find(int i1, int i2, ll m) {
	ll res = LLONG_MAX, l, r;
	l = lower_bound(a[i1].begin(), a[i1].end(), m) - a[i1].begin();
	r = upper_bound(a[i2].begin(), a[i2].end(), m) - a[i2].begin();
	if (l == a[i1].size() || a[i1][l] != m) l--;
	if (r == a[i2].size() || a[i2][r - 1] == m) r--;

	if (l >= 0 && r >= 0) {
		l = a[i1][l], r = a[i2][r];
		res = min(res, (l - m)*(l - m) + (r - l)*(r - l) + (r - m)*(r - m));
	}

	l = lower_bound(a[i2].begin(), a[i2].end(), m) - a[i2].begin();
	r = upper_bound(a[i1].begin(), a[i1].end(), m) - a[i1].begin();
	if (l == a[i2].size() || a[i2][l] != m) l--;
	if (r == a[i1].size() || a[i1][r - 1] == m) r--;
	if (l >= 0 && r >= 0) {
		l = a[i2][l], r = a[i1][r];
		res = min(res, (l - m)*(l - m) + (r - l)*(r - l) + (r - m)*(r - m));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 3; i++) {
			while (!a[i].empty()) a[i].pop_back();
		}
		cin >> aa >> bb >> cc;
		for (int i = 0; i < aa; i++) {
			cin >> n;
			a[0].pb(n);
		}
		for (int i = 0; i < bb; i++) {
			cin >> n;
			a[1].pb(n);
		}
		for (int i = 0; i < cc; i++) {
			cin >> n;
			a[2].pb(n);
		}
		sort(all(a[0]));
		sort(all(a[1]));
		sort(all(a[2]));
		ll res = LLONG_MAX;

		ll m;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				m = a[i][j];
				if (i == 0) {
					res = min(res, find(1, 2, m));
				}
				else if (i == 1) {
					res = min(res, find(0, 2, m));
				}
				else res = min(res, find(0, 1, m));
			}
		}
		cout << res << "\n";
	}
	return 0;
}
