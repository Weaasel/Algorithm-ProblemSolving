//동방 프로젝트(Large)
//Dynamic programming, prefix sum, sweeping

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <functional>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <complex>
#include <limits.h>
#include <list>
#define all(v) (v).begin(),(v).end()
#define sz(v) ((v).size())
#define F(i,s,e) for(int i=s;i<=e;i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using pdd = pair<double, double>;
using pil = pair<int, ll>;

int n, m;
int p[1000010];

int main() {
	/*#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	#endif*/
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int ans = 0;
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		p[a]--;
		p[b]++;
	}
	for (int i = 1; i < n; i++) {
		p[i] += p[i - 1];
		if (p[i] >= 0) ans++;
	}
	cout << ans + 1;
}
