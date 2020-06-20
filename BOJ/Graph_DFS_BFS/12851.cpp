//숨바꼭질2
/*
  주어진 두 수직선 위의 좌표 n, k가 있을 때, n에서 k로 가는 최소 이동 횟수를 구하는 숨바꼭질1에서
  조건이 하나 추가된 문제이다.
  최소 이동 횟수 + 그 가짓수 까지 출력을 해야 한다.
  구현은 조금 귀찮지만 별다른 차이는 없다.
  dist를 업데이트하는 것은 무조건 1번이고 cnt를 업데이트 하는건 여러번이 될 수 있게 처리해주면 된다.
  
  이게 되는 이유는 queue상에 dist가 차이가 2 이상 나는 쌍은 존재할 수 없기 때문이다.
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
#define DIV 1000000007;
#define INF 1e+9

using namespace std;

int n, k;
int dist[100001], cnt[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	memset(dist, -1, sizeof(dist));
	cnt[n] = 1;
	dist[n] = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur - 1 >= 0 && (dist[cur - 1] == -1 || dist[cur-1] == dist[cur] + 1)) {
			if (dist[cur - 1] == -1) q.push(cur - 1);
			dist[cur - 1] = dist[cur] + 1;
			cnt[cur - 1] += cnt[cur];
		}
		if (cur + 1 <= 100000 && (dist[cur + 1] == -1 || dist[cur + 1] == dist[cur] + 1)) {
			if (dist[cur + 1] == -1) q.push(cur + 1);
			dist[cur + 1] = dist[cur] + 1;
			cnt[cur + 1] += cnt[cur];
		}
		if (cur * 2 <= 100000 && (dist[cur * 2] == -1 || dist[cur * 2] == dist[cur] + 1)) {
			if (dist[cur * 2] == -1) q.push(cur * 2);
			dist[cur * 2] = dist[cur] + 1;
			cnt[cur * 2] += cnt[cur];
		}
	}
	cout << dist[k] << "\n" << cnt[k];

	return 0;
}
