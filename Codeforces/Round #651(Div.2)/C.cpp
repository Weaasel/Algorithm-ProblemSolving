//C - Number Game	
/*
  1을 만들어서 상대방에게 넘겨주면 이기는 게임이므로,
  n이 들어오는 경우의 수에 따라 최선의 전략으로 이길 수 있을지 없는지 따졌다.
  몇가지만 예를 들자면,
  
  1. n이 홀수면 이긴다 (자기 자신으로 나눈다)
  2. n = 2^k (k >= 1) 꼴이면 진다. (홀수 divisor가 없기에 상대방에게 n-1, 즉 홀수를 쥐어주어야 한다.)
  3. n = 2^k * a (k>1, a는 홀수) 꼴이면 이긴다. 상대방에게 n = 2^k 꼴을 쥐어줄 수 있기 때문에.
  
  이런 식으로 따져주면 된다.
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

int T, n;
bool isp[35001];
vector<int> prime;
void era() {
	for (int i = 2; i < sqrt(35001); i++) {
		for (int j = i * i; j < 35001; j += i) {
			isp[j] = false;
		}
	}
	for (int i = 2; i < 35001; i++) if (isp[i]) prime.pb(i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(isp, true, sizeof(isp));
	era();
	cin >> T;
	bool flg;
	while (T--) {
		cin >> n;
		//n==1이면 짐
		if (n == 1) flg = false;
		else if (n == 2) flg = true;
		else if (n % 2 == 1) flg = true;
		else {
			int cnt = 0;
			vector<int> div;
			while (n % 2 == 0) {
				n /= 2; cnt++;
			}
			for (int p : prime) {
				if (p > n) break;
				if (n%p == 0) {
					while (n%p == 0) {
						n /= p;
						div.pb(p);
					}
				}
			}
			if (n > 1) div.pb(n);

			//2*소수 1개 꼴이면 짐
			if (cnt == 1 && div.size() == 1) flg = false;
			//2^n꼴이면 짐
			else if (div.size() == 0) flg = false;
			//2*소수 여러개 꼴이면 이김
			else if (cnt == 1 && div.size() > 1) flg = true;
			//2^n * 소수 1개 이상이면 이김
			else if (cnt > 1 && div.size() > 0) flg = true;
		}
		if (flg) cout << "Ashishgup\n";
		else cout << "FastestFinger\n";
	}
	return 0;
}
