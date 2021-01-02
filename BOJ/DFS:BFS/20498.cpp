//C = 15
//Tree, dfs, Dynamic Programming
/*
  1. 우선 full binary tree는 높이가 낮은것을 이용해 뭔가를 하자.
  2. 어떤 덩어리가 만들어지면 트리가 어떤 모양이 될 지 생각하자.
  3. 트리에서 경로상의 정점값들의 합을 최대화하는 문제이므로 적어도 리프-리프 임을 알 수 있다.
  4. 합쳐진 상태에서 트리의 지름은, 합쳐진 거대정점에 연결된 체인들 중 가장 길이가 긴 2개를 포함한다.
  5. 필요한 정보는 어떤 정점 u를 루트로 하는 서브트리의 정점값들의 합(subs[u])와 u의 양쪽으로 뻗은 체인들 중 가장 큰 값(L[u], R[u])
  6. 남은 것은 case work. l,r부터 올라가면서 lca에서 만날때까지 제외할 subtree 세면서 쓸 수 있는 chain을 모으자.
    lca가 1(전체루트) 가 아니라면 반대쪽 서브트리에서 연결할 수 있는 방법도 있으므로 역시 고려해 주자.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define eps 1e-8
#define pi 3.14159265
const ll MOD = 998244353;
const int INF = 1e9 + 7;
using namespace std;
//getline(cin, s);

ll n, k, w[262144], subs[262144], L[262144], R[262144], res;

void dfs(int idx) {
	subs[idx] = w[idx];
	if (idx * 2 + 1 <= n) {
		dfs(idx * 2);
		dfs(idx * 2 + 1);
		subs[idx] += subs[idx * 2] + subs[idx * 2 + 1];
		L[idx] = max(L[idx * 2], R[idx * 2]) + w[idx * 2];
		R[idx] = max(L[idx * 2 + 1], R[idx * 2 + 1]) + w[idx * 2 + 1];
	}
}

ll get(int l, int r) {
	ll ret = 0, mid = 0;
	priority_queue<ll> cur;
	cur.push(0);
	cur.push(0);
	//몸통
	while (l != r) {
		int pl = l, pr = r;
		l /= 2;
		if (l * 2 != pl) { //오른쪽이면
			mid -= subs[l * 2];
			cur.push(L[l]);
		}
		r /= 2;
		if (r * 2 + 1 != pr) { //왼쪽이면
			mid -= subs[r * 2 + 1];
			cur.push(R[r]);
		}
	}

	mid += subs[l];
	ll m1 = cur.top(); cur.pop();
	ll m2 = cur.top(); cur.pop();
	ret = mid + m1 + m2;
	while (l > 1) {
		int pl = l;
		l /= 2;
		mid += w[l];
		if (l * 2 == pl) ret = max(ret, mid + m1 + R[l]);
		
		else ret = max(ret, mid + m1 + L[l]);
		
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	while (pow(2, k) < n + 1)k++;
	dfs(1);
	for (int i = 1; i <= n; i++) res = max(res, L[i] + R[i] + w[i]);
	for (int i = n / 2 + 1; i <= n; i++) {
		int j = i + k - 1;
		if (j > n) break;
		res = max(res, get(i, j));
	}

	cout << res;
	return 0;
}
