//D - Odd-Even Subsequence	
/*
  size k 에 대해 답이 될 수 있는 minimum cost를 binary search한다.
  그러면 현재 cost c가 valid한가?(size k 이상의 subsequence를 만들 수 있는가?) 의 문제로 바뀐다.
  
  이는 cost c에 대해 부합하도록 최대한 많은 원소를 집어넣고 이 개수가 k 이상인지를 보면 되는데,
  우선 c 이하인 것들을 모두 포함시켜 부분수열을 만들고,
  짝수번째 / 홀수번째 중 하나만 골라서 c 보다 큰 값들을 넣을 수 있으므로, 그 두 경우에 대해 각각 계산하여 더 많은 것을 택한다.
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
ll a[200001], ans = INF;
bool chk(ll val) {
	int cnt = 0;
	vector<int> used;
	used.pb(0);
	for (int i = 1; i <= n; i++) {
		if (a[i] <= val) {
			cnt++;
			used.pb(i);
		}
	}
	used.pb(n+1);
	//홀수집합에 큰애들 포함시키기
	int ccnt = 0, sz = used.size(), res1 = 0, res2 = 0;
	for (int i = 1; i < sz; i++) {
		if (ccnt % 2 == 0 && used[i] - used[i-1] > 1) {
			res1++;
			ccnt += 2;
		}
		else {
			ccnt++;
		}
	}
	//짝수집합에 큰애들 포함시키기
	ccnt = 0;
	for (int i = 1; i < sz; i++) {
		if (ccnt % 2 == 1 && used[i] - used[i - 1] > 1) {
			res2++;
			ccnt += 2;
		}
		else {
			ccnt++;
		}
	}
	return cnt + max(res1,res2) >= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	ll l = 1, r = INF, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
	
	return 0;
}
