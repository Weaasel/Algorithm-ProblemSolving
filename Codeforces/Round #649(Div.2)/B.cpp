//B - Most socially-distanced subsequence	

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
int T, n;
ll a[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<ll> v;
		bool sgn = false;
		v.pb(a[0]);
		//inc
		if (a[1] > a[0]) sgn = true;
		//dec
		else sgn = false;
		int wlk = 1;
		while (wlk < n - 1) {
			if (sgn) {
				if (a[wlk] > a[wlk + 1]) {
					v.pb(a[wlk]);
					sgn = false;
				}
				wlk++;
			}
			else {
				if (a[wlk] < a[wlk + 1]) {
					v.pb(a[wlk]);
					sgn = true;
				}
				wlk++;
			}
		}
		v.pb(a[n - 1]);
		cout << v.size() <<"\n";
		for (int i : v) cout << i << " ";
		cout << "\n";
	}
	return 0;
}
