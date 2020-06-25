//센서
//greedy
/*
  모든 점에 길이 0짜리 구간을 깔아놓고, 총 n개의 구간을 k개로 만들기 위해 n-k개를 합친다.
  각 구간 사이의 거리를 모두 알고 있으므로 짧은 순으로 합치면 된다.
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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9
const ll DIV = 1e9 + 7;
using namespace std;

int n, k, num;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.pb(num);
	}
	v.erase(unique(all(v)), v.end());
	sort(all(v));
	n = v.size();
	//n-k개의 구간을 합치면 됨
	vector<int> vv;
	for (int i = 1; i < n; i++) vv.pb(v[i] - v[i - 1]);
	sort(all(vv));
	int res = 0;
	for (int i = 0; i < n - k; i++) res += vv[i];
	cout << res;
	return 0;
}
