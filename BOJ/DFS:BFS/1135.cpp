//뉴스 전하기
//Tree, dfs

/*
  트리형태에서의 단순 dfs문제.
  현재 노드에서의 최소 소요시간은, 자식들의 소요시간을 모아 정렬하고,
  오래걸리는 노드부터 먼저 전화를 걸어주는 시간이다.
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
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 1e9
#define base 100000
using namespace std;

int n, par;
vector<int> adj[51];

int go(int u) {
	int res = 0;
	vector<int> vec;
	for (int v : adj[u]) {
		vec.pb(go(v));
	}
	if (vec.empty()) return res;
	sort(all(vec));
	for (int i = 0; i < vec.size(); i++) {
		int tmp = vec[i] + adj[u].size() - i;
		res = max(res, tmp);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> par;
		if(par!=-1)adj[par].pb(i);
	}
	cout << go(0);
	return 0;
}
