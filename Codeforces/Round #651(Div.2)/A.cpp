//A - Maximum GCD	
/*
  1 ~ n 중 두 수를 뽑아서 gcd를 가장 크게 하는 방법은 n/2, n 을 뽑는 것이다.
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
int a[200001];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n % 2 == 1) n--;
		cout << n / 2 << "\n";
	}
	return 0;
}
