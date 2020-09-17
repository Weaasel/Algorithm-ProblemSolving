//숫자
//DFS, dp
/*
  어떤 수로부터 출발하는 수열은 결국 사이클을 돌게 된다.
  일반적으로 달팽이 형태(__0)라고 하자.
  
  n에서 출발하는 수열의 최소값을 res[n]이라 하자.
  res[n] = min(n, res[SK(n)]) 이 성립한다.
  문제는 사이클에서의 반환이다.
  사이클에 대한 처리를 단순히 res[u] = u 로 하게 되면
  사이클의 시작이 되는 점 u 역시 사이클 안의 최소값을 res[u] 로 가져야 하는데 이 부분을 놓치게 된다.  
  
  간단하게 재귀를 두 바퀴 돌리면 해결된다.
  visited 배열을 boolean이 아닌 int 로 선언하고,
  vis[n] == 2 일 때 사이클 반환을 시작하는 것이다.
  이렇게 하면 초기에는 사이클 안의 최소값을 res[n]으로 가지지 못하지만,
  한바퀴 더 돌면서 업데이트된 최소값으로 가질 수 있게 된다.
  
  ps. 이런 테크닉은 원형 배열을 펼 때 길이를 2배로 펴는 것과 유사하다.
*/

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
const int mxn = 3200001;

int a, b, k;
int val[10], res[mxn], vis[mxn], nxt[mxn];
long long ans;

int dfs(int n, int mn) {
	vis[n]++;
	int v = nxt[n];
	if (vis[v] < 2) mn = min(mn, dfs(v, v));
	else if (res[v] > 0)mn = min(mn, res[v]);
	res[n] = mn;
	return mn;
}

int main() {
	cin >> a >> b >> k;
	for (int i = 0; i < 10; i++) val[i] = pow(i, k);
	for (int i = 0; i < mxn; i++) {
		int u = i, v = 0;
		while (u > 0) {
			v += val[u % 10];
			u /= 10;
		}
		nxt[i] = v;
	}
	for (int i = a; i <= b; i++)
		if (vis[i] == 0) dfs(i, i);
	for (int i = a; i <= b; i++) ans += res[i];
	cout << ans;
	return 0;
}
