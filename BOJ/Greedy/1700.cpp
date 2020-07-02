//멀티탭 스케줄링
//greedy, priority_queue
/*
  n구 멀티탭이 주어지고, 전자제품들을 순서대로 k회 사용할 때(중복 가능) 멀티탭을 가장 효율적으로 쓰는 방법은 무엇일까?
  답은 간단하다. 멀티탭에 자리가 있으면 이번에 쓸 제품을 꽂고, 미래에 가장 늦게 나올 제품을 뽑는다.
  이 과정에서 마치 그래프처럼 각 index 의 다음번 등장 index 를 nxt라는 배열에 저장하고, 이 값을 가지고 priority_queue 에 넣어
  가장 늦게 나올 전자제품이 무엇인지 알 수 있게 한다.
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
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int n, k;
int a[101], nxt[101];
bool use[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) cin >> a[i];
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (a[i] == a[j]) {
				nxt[i] = j;
				break;
			}
		}
		if (nxt[i] == 0) nxt[i] = k;
	}
	priority_queue<pii> pq; //nxt랑 현재
	int res = 0;
	for (int i = 0; i < k; i++) {
		if (use[a[i]]) {
			vector<pii> tmp;
			while (pq.top().second != a[i]) {
				tmp.pb(pq.top()); pq.pop();
			}
			pii p = pq.top(); pq.pop();
			p.first = nxt[i];
			pq.push(p);
			for (pii p : tmp) pq.push(p);
		}
		else if (pq.size() < n) {
			use[a[i]] = true;
			pq.push({ nxt[i], a[i] });
		}
		else {
			res++;
			pii p = pq.top(); pq.pop();
			int cur = p.second;
			use[cur] = false;
			use[a[i]] = true;
			pq.push({ nxt[i], a[i] });
		}
	}
	cout << res;
	return 0;
}
