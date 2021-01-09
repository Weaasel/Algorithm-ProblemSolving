//아름다운 만영로
//Hashing, Rabin Karp, lca, dfs, dynamic programming
/*
  내 힘으로 푼 해시 문제중에 가장 빡셌다.
  핵심 아이디어는 dfs + 해싱 + lca다.
  찾을 문자열의 길이가 k이므로 k번째 조상과 그 링크값만 알면 dfs를 하며 이전 해시값을 이용해 현재 해시값을 구할 수 있다.
  트리상에서 해당 노드에서 끝나는 문자열을 1가지일 테니, 그 1가지의 해시값을 구해 원래 해시값과 비교하여 정답을 세어 주자.
  k번째 조상을 전처리할때 lca를 사용한다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x first
#define y second
#define pb push_back
#define pic pair<int, char>
using namespace std;
//getline(cin, s);

int n, u, v, k, res;
int pre[505050][21], lv[505050];
char kth[505050]; //아래로 k번째 link값
pll h[505050];
ll shash;
ll p = 27, ppow[505050];
string s;
vector<pic> adj[505050], radj[505050];
map<pii, char> m;

void make_tree(int u) {
	for (pic p : adj[u]) {
		int v = p.x;
		if (lv[v] > 0) continue;
		pre[v][0] = u;
		lv[v] = lv[u] + 1;
		make_tree(v);
	}
}

void init_pre() {
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j <= n; j++) {
			pre[j][i] = pre[pre[j][i - 1]][i - 1];
		}
	}
}

char find(int u) {
	int u1 = u, d1 = k;
	for (int i = 20; i >= 0; i--) {
		if (d1 < (1 << i)) continue;
		u1 = pre[u1][i];
		d1 -= 1 << i;
	}
	int u2 = u, d2 = k-1;
	for (int i = 20; i >= 0; i--) {
		if (d2 < (1 << i)) continue;
		u2 = pre[u2][i];
		d2 -= 1 << i;
	}
	if (u1 == 0 || u2 == 0) return 'A';
	else return m[{u1, u2}];
}

pll go(int u) {
	if (h[u].y > -1) return h[u];
	if (radj[u].empty()) return h[u] = { 0,0 };
	int v = radj[u][0].x;
	char c = radj[u][0].y;
	pll prv = go(v);
	ll cur = prv.x, len = prv.y;
	if (len < k) {
		cur += ppow[k - 1 - len] * (c - 'a' + 1);
		len++;
	}
	else {
		cur -= ppow[k - 1] * (kth[v] - 'a' + 1);
		cur *= p;
		cur += c - 'a' + 1;
	}
	return h[u] = { cur,len };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		char c;
		cin >> u >> v >> c;
		adj[u].pb({ v,c });
		m[{u, v}] = c;
		radj[v].pb({ u,c });
	}
	cin >> s;

	k = s.size();
	lv[1] = 1;
	make_tree(1);
	init_pre();
	for (int i = 1; i <= n; i++) {
		kth[i] = find(i);
		h[i] = { -1,-1 };
	}
	ppow[0] = 1;
	for (int i = 1; i <= k - 1; i++) ppow[i] = ppow[i - 1] * p;
	for (int i = 0; i < k; i++) {
		shash *= p;
		shash += s[i] - 'a' + 1;
	}

	for (int i = 1; i <= n; i++) {
		pll p = go(i);
		if (p.y == k && shash == p.x) res++;
	}
	cout << res;

	return 0;
}
