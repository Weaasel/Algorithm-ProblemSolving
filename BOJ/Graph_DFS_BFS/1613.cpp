//역사
//Graph, Floyd-warshall

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

int n, k, s, u, v;
bool adj[401][401];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (adj[i][k] && adj[k][j]) {
					adj[i][j] = true;
				}
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> u >> v;
		adj[u][v] = true;
	}
	floyd();
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> u >> v;
		if (adj[u][v]) cout << "-1\n";
		else if (adj[v][u]) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
