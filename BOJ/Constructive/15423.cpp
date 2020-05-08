//Canonical Coin Systems
//Constructive, Brute force
/*
  주어진 coin system(ex. 1, 2, 4, 8 센트 동전) 에 따라
  greedy한 솔루션과 dp 솔루션이 같은지 다른지를 출력하는 문제이다.
  
  예를 들어, {1, 5, 8} 과 같은 coin system에서는
  12원을 표현하기 위해서
    1) Greedy
      8 * 1 + 1 * 4 = 12. 5개의 동전이 필요하고
    2) DP
      5 * 2 + 1 * 2 = 12. 4개의 동전이 필요하다.
  이런 식으로 greedy solution이 비효율적인 경우에 non-canonical하고, 반대로 greedy solution이 항상 옳은 경우에는 canonical이다.
  
  처음에는 주어진 coin system 상에서 규칙을 찾아 정답을 판단하기 위해 고민을 해 봤지만, 별다른 규칙을 찾을 수 없었다.
  
  동전의 개수가 100개이고, 값의 최대값은 10^6 인 점을 이용하여
  dp solution을 전부 전처리해서 계산해 두고,
  
  1 ~ 2* 10^6 value를 가지는 모든 값들에 대해 greedy solution을 수행해 dp solution과 비교하면 되는 문제였다.
  
  조금은 허탈한 풀이이긴 하지만 검사를 해야 할 돈이 2*10^6 까지임을 판단하는 문제였던 것 같다.
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
#define INF 2000000000
using namespace std;
int n, c[101];
int dp[2000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> c[i];
	sort(c, c + n);
	fill(dp, dp + 2000001, INF);
	dp[0] = 0;
	for (int i = 1; i < 2000001; i++) {
		for (int j = 0; j < n; j++) {
			if (c[j] > i) break;
			dp[i] = min(dp[i], dp[i - c[j]] + 1);
		}
	}
	for (int i = 1; i <= 2 * c[n - 1]; i++) {
		int val = i;
		int cnt = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (c[j] > val) continue;
			if (!val) break;
			cnt += val / c[j];
			val %= c[j];
		}
		if (cnt > dp[i]) {
			cout << "non-canonical";
			return 0;
		}
	}
	cout << "canonical";
	return 0;
}
