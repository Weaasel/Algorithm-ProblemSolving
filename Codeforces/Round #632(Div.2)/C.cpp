//C. Eugene and an array

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
ll n, psum[200001], l, res, num;
map<ll, ll> pos;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> psum[i];
		psum[i] += psum[i - 1];
	}
	pos[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (pos.count(psum[i]) > 0) {
			l = max(l, pos[psum[i]] + 1);
		}
		res += i - l;
		pos[psum[i]] = i;
	}
	cout << res;
	return 0;
}
