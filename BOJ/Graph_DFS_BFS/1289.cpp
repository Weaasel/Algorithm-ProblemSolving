//트리의 가중치
//Tree, DFS, Mathematics

/*
  주어진 트리구조에서 모든 path에 대응하는 값을 return하면 되는 문제입니다.
  각 path에 대응하는 값은 path를 구성하는 모든 edge의 곱으로 계산합니다.
  
  대략적인 식은
  res(root) = sum of(edge) + sum of(res(child)) + 각 child로 뻗는 길들로부터 얻을 수 있는 값
  로 나옵니다.
  첫 항은 root의 각 child로의 1-length path는 그전 child들로부터 구할수 없으니 더해줘야 하고,
  두번째 항은 child를 root로 갖는 subtree에서 나올 수 있는 path들을 다 더해주겠다는 tree dfs에서 자주 사용하는 방식입니다.
  마지막 항이 서술하기가 조금 어려운데, 각각의 subtree에서 나올 수 없는 값인, child - root - another child들의 값입니다.
  
  마지막 항을 구하려면, 아래의 식을 계산해야 합니다.
        root
   child1  child2 구조를 가정합시다.
   
  [아래에서 올라와 child1로 끝나는 모든 path들] * child1-root * [아래에서 올라와 child2로 끝나는 모든 path들] * root-child2
  들의 조합을 모두 더해주어야 새롭게 생기는 path들을 표현 가능하다는 말입니다.
  
  이 계산을 naive하게 구하면 시간초과가 나게 되고,
  결국은 [아래에서 올라와 child1로 끝나는 모든 path들] 이 어떤 집합이라고 가정했을 때,
  [a1, a2, a3, ... ,ai] , [b1, b2, b3, ... bj] 에서 a, b 한 개씩 골라 곱한 수들의 합이므로,
  sum of(a) * sum of(b) 로 계산할 수 있을 것이고,
  
  여러 child 조합들에 대해 확장하면
  ((a + b + c + ...)^2 - (a^2 + b^2 + c^2 + ...))/ 2 의 꼴이 될 것입니다.
  따라서 dfs 의 반환값을 pair로 두고, {답, 해당 노드에서 끝나는 path들의 합} 을 return하는 dfs 함수를 구현하면 되겠습니다.
  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define DIV 1000000007LL

using namespace std;

ll n, u, v, c;
vector<pll> adj[100001];
pll dfs(int u, int pre) {
	pll res = { 0, 0};
	vector<ll> vv;
	for (pll p : adj[u]) {
		ll v = p.first, e = p.second;
		if (v == pre) continue;
		pll tmp = dfs(v, u);
		res.first += tmp.first;
		tmp.second += 1;
		ll a = (tmp.second * e) % DIV;
		res.first += a;
		res.first %= DIV;
		vv.pb(a);
	}
	ll sum = 0, sumofpow = 0;
	for (ll t : vv) {
		sum += t;
		sumofpow += t * t;
		sum %= DIV;
		sumofpow %= DIV;
	}
	res.second = sum;
	sum *= sum;
	sum -= sumofpow;
	if (sum % 2 == 1) sum += DIV;
	sum /= 2LL;
	sum %= DIV;
	res.first += sum;
	res.first %= DIV;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> c;
		adj[u].pb({ v, c });
		adj[v].pb({ u, c });
	}
	cout << dfs(1, -1).first;
	return 0;
}
