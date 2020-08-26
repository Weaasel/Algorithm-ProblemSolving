//제곱 ㄴㄴ
//binary search, eratosthenes sieve, inclusion–exclusion principle
/*
  제곱 ㄴㄴ수란 제곱수로 나누어떨어지지 않는 수를 말한다. (ex. 8은 제곱ㄴㄴ수가 아니다.)
  1 <= k <= 1,000,000,000 인 k가 주어질 때, k번째 제곱ㄴㄴ수 를 구하는 문제이다.
  
  결론부터 말하자면 역시 binary search다.
  어떤 수 num에 대해 num이 몇번째 제곱ㄴㄴ수인지를 판단해서 구간을 줄여 나간다.
  n이 몇번째 제곱ㄴㄴ수이냐는 물음은 n에서 제곱ㅇㅇ수의 개수를 빼는 것으로 해결 가능한데,
  제곱ㅇㅇ수, 즉 제곱수로 나누어떨어지는 수의 개수는 포함-배제의 원리로 구할 수 있다.
  자세한 내용은 블로그에 업로드할 예정이다.
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
const ll INF = 1e10;
const int mx = 50000;

using namespace std;

ll k;
bool isP[mx];
int d[mx];
vector<ll> prime;

int decom(int n) {
	int cnt = 0;
	for (int p : prime) {
		if (p > n) break;
		if (n%p == 0) {
			cnt++;
			n /= p;
		}
	}
	if (n == 1) return cnt;
	else return -1;
}

void era() {
	memset(isP, true, sizeof(isP));
	for (int i = 2; i < sqrt(mx); i++) {
		for (int j = i * i; j < mx; j += i) {
			isP[j] = false;
		}
	}
	for (int i = 2; i < mx; i++) if (isP[i]) prime.pb(i);
	for (int num = 2; num < mx; num++) d[num] = decom(num);
	return;
}

//소인수 하나짜리(소수), 소인수 두개짜리, 소인수 세개짜리 ...6까지만 하면됨.
bool chk(ll n) {
	ll cnt = 0;
	for (int i = 1; i <= 6; i++) {
		for (int num = 2; num < mx; num++) {
			if (d[num] == i) {
				int sign = i % 2 ? 1 : -1;
				cnt += n / (num*num) * sign;
			}
		}
	}
	return n - cnt < k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	era();
	ll l = 1, r = INF;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (chk(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}
