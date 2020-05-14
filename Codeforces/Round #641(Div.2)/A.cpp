//A - Orac and Factors	
/*
  n을 나누는 1이 아닌 가장 작은 수를 더해가는 문제이다.
  n이 짝수일 때는 2씩 더해간다. 
  n이 홀수일 때는 한번만 홀수 약수가 더해지면 짝수가 된다.
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

ll T, n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		if (n % 2 == 0) {
			cout << n + 2 * k << "\n";
		}
		else {
			for (int i = 3; i <= n; i += 2) {
				if (n%i == 0) {
					n += i;
					break;
				}
			}
			cout << n + 2 * (k-1) << "\n";
		}
	}
	return 0;
}
