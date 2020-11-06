//죄수에게 주는 뇌물
//Dynamic programming with 2-dimension
/*
  죄수를 풀어주는 과정을 역으로 진행한다고 가정하면,
  죄수들을 경계로 나뉘어 있는 여러 구간들을 인접한 것끼리 합치는 과정으로 바꿔 생각할 수 있다.
  2번 예시를 예로 들면
  {1,2}, {4,5}, {7,13}, {14,20} 인 구간들을
  하나 씩 연결하는 과정이고, 그 비용은 인접한 두 구간에 존재하는 수의 개수로 표현된다.
  
  dp[l][r]: 구간 [l,r] 에 대해 합치는 최소비용 이라고 하자.
  [l,r] 사이에 있는 한 구간을 정해서 해당 구간 기준으로 왼쪽을 전부 합치고 오른쪽을 전부 합치고 마지막에 전체를 합치는 연산이라고 생각할 수 있다.
  이러면 식은 아래와 같이 표현된다.
  dp[l][r] = min(dp[l][l]+dp[l+1][r], dp[l][l+1] + dp[l+2][r], ... + dp[l][r-1] + dp[r][r]) + [l,r] 구간에 존재하는 방의 개수
  라고 식을 세울 수 있다.
  한가지 주의할 점은 구간을 표현할 때 (l,r) 형태로 표현해야 연속하게 배치된 죄수들 각각에 대한 구간을 표현할 수 있다는 점이다.
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1e15;

ll p, q, a[102];
ll dp[102][102];
vector<pii> v;

ll go(int l, int r) {
	if (r <= l) return dp[l][r] = 0;
	if (dp[l][r] > -1) return dp[l][r];
	
	ll ret = INF;
	for (int i = l; i < r; i++) 
		ret = min(ret, go(l, i) + go(i + 1, r));	
	return dp[l][r] = ret + v[r].second - v[l].first - 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> p >> q;
	for (int i = 0; i < q; i++) cin >> a[i];
	sort(a, a + q);

	v.pb({0,a[0]-1});
	for (int i = 1; i < q; i++) v.pb({a[i-1], a[i]});
	v.pb({a[q-1]+1,p+1});

	cout << go(0, v.size() - 1);
	return 0;
}
