//소수의 연속합
//eratosthenes, Two Pointer
/*
  어차피 따지는것은 연속합이고, 주어진 수 n이 되는지를 볼 것이므로,
  정렬된 상태의 소수집합을 투포인터 형태로 scan하면서 답이 되는 가지수를 체크하면 된다.
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

bool isp[4000001];
int n;
vector<int> prime;
void era() {
	memset(isp, true, sizeof(isp));
	for (int i = 2; i < sqrt(4000001); i++) {
		for (int j = i * i; j < 4000001; j += i) {
			isp[j] = false;
		}
	}
	for (int i = 2; i < 4000001; i++) if (isp[i]) prime.pb(i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	era();
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	int w1 = 0, w2 = 0, sum = 2, res = 0;
	int sz = prime.size();
	while (w1 <= w2 && w2 < sz) {
		if (n == sum) {
			res++;
			w2++;
			if (w2 == sz) break;
			sum += prime[w2];
		}
		else if (n > sum) {
			w2++;
			if (w2 == sz) break;
			sum += prime[w2];
		}
		else if (n < sum) {
			sum -= prime[w1];
			w1++;
		}
	}
	cout << res;
	return 0;
}
